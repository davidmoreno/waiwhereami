/**
  * OSM 2 WAI -- Converts from OSM XML files to a WAI set.
  * Copyright (C) 2008 David Moreno Montero <monjemono@gmail.com>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include <math.h>

#include <QFile>
#include <QMap>

#include "kdnode.h"
#include "way.h"

//#define CHECK_POINT 300023808

int KdNode::boundingBox[4]={0,0,0,0};

KdNode::KdNode(CoordinateList l){
    less=NULL;
    more=NULL;
    prepareNode(l.begin(), l.end(), l.count(), true);
}

KdNode::~KdNode(){
    if (less)
        delete less;
    if (more)
        delete more;
}

/**
 * @short Do real splitting, alternating latitude and longitude, and stops when less than MAX_AT_BUCKET points are at the list.
 */
void KdNode::prepareNode(CoordinateList::Iterator begin, CoordinateList::Iterator end, int count, bool atLatitude){
    if (count<MAX_AT_BUCKET){
        less=NULL;
        more=NULL;
        key=0;


        // Dirty way to copy a sublist...
        while(begin!=end){
            list.append(*begin);
            ++begin;
        }
        //qSort(list.begin(), list.end(), wayIdLessThan);

        return;
    }
    int mid=count/2;

    if (atLatitude){
        qSort(begin, end, latitudeLessThan);
        key=(begin+mid)->intLatitude();
    }
    else{
        qSort(begin, end, longitudeLessThan);
        key=(begin+mid)->intLongitude();
    }

    less=new KdNode(begin,     begin+mid, mid,       !atLatitude);
    more=new KdNode(begin+mid, end,       count-mid, !atLatitude);
}

/**
 * @short Saves the kdtree to a tree and a data files.
 *
 * It opens both files, and mmaps the tree file. Then calls the recursive save(void *tree,QFile data).
 *
 * Returns whether the tree could be saved.
 */
bool KdNode::save(const QString &treefile, const QString &datafile, const QString &namefile){
    QFile tree(treefile);
    tree.remove();
    tree.open(QFile::ReadWrite);

    QFile data(datafile);
    data.remove();
    data.open(QFile::WriteOnly);

    QFile namedata(namefile);
    namedata.remove();
    namedata.open(QFile::WriteOnly);


    int kdtreefilesize=nodeCount()*4*3;
    qDebug("%s:%d Tree file size will be %d",__FILE__,__LINE__,kdtreefilesize);
    for (int i=0;i<kdtreefilesize;i++)
        tree.write(".");
    tree.close(); // force write of the dots, and size set.
    tree.open(QFile::ReadWrite);

    void *mmaptree=tree.map(0, kdtreefilesize);

    if (!mmaptree){
        qDebug("%s:%d Could not mmap kdtree file",__FILE__,__LINE__);
        return false;
    }

    int currentPos=0;
    save((qint32*)mmaptree, data, namedata, currentPos);

    Q_ASSERT(kdtreefilesize==currentPos);

    return true;
}


/**
 * @short Saves the kdtree to two files: the kdtree itself and kdtree data.
 *
 * The first file should be passed as a mmaped file (for easy editing), and the data file as a QFile.
 *
 * Current pos is used as counter of the next pos to be used (it is always a *3 multiply). Returns the position
 * where current record has been saved.
 */
int KdNode::save(qint32 *mem, QFile &data, QFile &nameData, int &currentPos){
    int mypos=currentPos;
    //qDebug("%s:%d mypos %d",__FILE__,__LINE__,mypos);
    currentPos+=3;

    if (less){
        mem[mypos]=key;
        mem[mypos+1]=less->save(mem,data, nameData, currentPos)*sizeof(qint32);
        mem[mypos+2]=more->save(mem,data, nameData, currentPos)*sizeof(qint32);
        //qDebug("%s:%d %d l %d m %d",__FILE__,__LINE__,mypos, mem[mypos+1],mem[mypos+2]);
    }
    else{
        mem[mypos]=0;
        mem[mypos+1]=data.pos();
        mem[mypos+2]=-1;
        //qDebug("%s:%d at %d data pointer",__FILE__,__LINE__,mypos*4);

        saveData(data, nameData);
    }
    return mypos;
}

/**
 * @short Counts the number of nodes for this KdTree.
 *
 * Usefull to have how big should the kdfile be.
 */
int KdNode::nodeCount(){
    if (less)
        return less->nodeCount()+more->nodeCount()+1;
    return 1;
}

/**
 * @short Counts the number of points on this tree
 *
 * Usefull to count all points, and get no one lost... just an internal check.
 */
int KdNode::pointCount(){
    if (less)
        return less->pointCount()+more->pointCount();
    return list.count();
}

/**
 * @short Saves the data to the data file.
 */
void KdNode::saveData(QFile &data, QFile &nameData){
    qint32 cpx,cpy;
    quint32 posAtNames=0;
    // First count how many ways are on this area. Do not count no-way coordinates
    QMap<Way*, CoordinateList> coordinateListDict;
    foreach (Coordinate c,list){
        foreach(Way *w, c.getWay()){
            if (!w->getSkip())
                coordinateListDict[w].append( c );
        }
    }
    unsigned char wayCount=coordinateListDict.count();
    wayCount-=1; // I count one more than needed, and store one less to get from 1 to 256.
    data.write((char*)&wayCount,1); // 1-256, 0 is 1.
    //qDebug("%s:%d %d ways",__FILE__,__LINE__,wayCount);

    WayList waysByLayer=coordinateListDict.keys();
    qSort(waysByLayer.begin(),  waysByLayer.end(), &typeIdGreaterThan);

    foreach (Way *way, waysByLayer){
        // I prepare a coordinate list for this area
        // There are points without ways (a petrol station, a bus stop...)
        CoordinateList coords=coordinateListDict[way];

        CoordinateList coordinateListReal;

        if (way->typeId()>127)
            coordinateListReal=way->getCoordinateList();
        else
            coordinateListReal=getCoordinatesAtWay(coords, way);
        //qDebug("%s:%d done coord list for this way",__FILE__,__LINE__);

        unsigned char np=coordinateListReal.count();

        Q_ASSERT(coordinateListReal.count()<256);
        Q_ASSERT(np>0);

        //qDebug("%s:%d %d points out of %d",__FILE__,__LINE__,np,way->getCoordinateList().count());

        np--;
        data.write((char*)&np,1); // count
        np=way->typeId();
        //qDebug("%s:%d way %d type %d",__FILE__,__LINE__,nway,np);
        data.write((char*)&np,1); // type

        posAtNames=saveNameData(way, nameData);

        data.write((char*)&posAtNames,sizeof(qint32));
        //qDebug("%s:%d wayid %d",__FILE__,__LINE__,lastWayId);

        foreach(Coordinate cc, coordinateListReal){
            way->useCoordinate(cc);
            cpx=cc.intLongitude();
            cpy=cc.intLatitude();
            // Serialize points.
            data.write((char*)&cpx,sizeof(qint32));
            data.write((char*)&cpy,sizeof(qint32));
            //qDebug("%s:%d p %d %d",__FILE__,__LINE__,cpx,cpy);
            if (!boundingBox[0] || cpx<boundingBox[0]) boundingBox[0]=cpx;
            if (!boundingBox[1] || cpx>boundingBox[1]) boundingBox[1]=cpx;
            if (!boundingBox[2] || cpy<boundingBox[2]) boundingBox[2]=cpy;
            if (!boundingBox[3] || cpy>boundingBox[3]) boundingBox[3]=cpy;
        }
    }
}

int KdNode::saveNameData(Way *w, QFile &data){
    w->saveData(data);
    return w->getNamePos();
}

static void printCoordinateList(const char *str, const CoordinateList &L){
    printf("%25s ",str);
    foreach(Coordinate l, L){
        printf("%g ",l.latitude());
    }
    printf("\n");
}

/**
 * @short From a CoordinateList::Iterator it gets, in the way order, the coordinates at that list
 *
 * It also gathers every coordinate that is after and before any coordinate that is at the list; for example:
 *
 * I list  : E D B
 * way list: A B C D E F G
 * returns : A B C D E F
 *
 * A is there because it is before B, C is after B, C is before D and F is after E
 */
CoordinateList KdNode::getCoordinatesAtWay(const CoordinateList &coords, Way *way){
    //qDebug("%s:%d prepare coord list for this way %d, up to %d",__FILE__,__LINE__, lastWayId, wayCoords.count());
    CoordinateList coordinateListReal;
    CoordinateList wayCoords=way->getCoordinateList();

    //printCoordinateList("coords",coords);

    CoordinateList orderedCoords;
    foreach(Coordinate wc, way->getCoordinateList()){
        foreach(Coordinate c, coords){
            if (c==wc){
                orderedCoords.append(wc);
            }
        }
    }
    CoordinateList::Iterator I=orderedCoords.begin(), endI=orderedCoords.end();
    CoordinateList::Iterator J=wayCoords.begin(), endJ=wayCoords.end();

    CoordinateList::Iterator PrevJ=endJ;
    int lastCopied=0;

    Coordinate prev=orderedCoords[0];

    while (I!=endI && J!=endJ){
        //printf("I %g J %g lc %d == %d %d %d\n",I->latitude(), J->latitude(), lastCopied, I->getId(),J->getId(),I->getId()==J->getId());
        if (PrevJ!=endJ && (*I)==(*PrevJ)){
            //qDebug("%s:%d ein!?? I skipped this?? %d",__FILE__,__LINE__,way->getId());
            ++I;
            continue; // go back to begining...
        }
        if ((*I)==(*J)){
            if (lastCopied==0 && PrevJ!=endJ){
                //printf("ap %g\n",PrevJ->latitude());
                coordinateListReal.append(*PrevJ);
            }
            lastCopied=2;
            //printf("am %g\n",I->latitude());
            coordinateListReal.append(*I);
            ++I;
        }
        else{
            if (lastCopied==2){
                //printf("al %g\n",J->latitude());
                coordinateListReal.append(*J);
                lastCopied=1;
            }
            else
                lastCopied=0;
        }
        PrevJ=J;
        ++J;
    }
    //printf("I -- J %g lc %d , == %d\n", J!=endJ ? J->latitude() : 0.0, lastCopied,J==endJ);
    if (lastCopied==2 && J!=endJ){
        //printf("a %g\n",J->latitude());
        coordinateListReal.append(*J);
    }
    Q_ASSERT(I==endI);

    return coordinateListReal;
}
