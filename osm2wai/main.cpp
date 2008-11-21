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

#include <QtCore/QCoreApplication>
#include <QFile>
#include <QXmlStreamReader>
#include <QList>
#include <QStringList>
#include <QTime>

#include "way.h"
#include "coordinate.h"
#include "kdnode.h"

void readXML(QXmlStreamReader &xml, QFile &f, CoordinateList &coords, WayList &ways);
void filterWays(WayList &wl);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QStringList args=a.arguments();
    if (args.count()<=1){
        qDebug("%s:%d I need an OSM file to convert.",__FILE__,__LINE__);
        exit(1);
    }

    QString osm(args.at(1));
    QFile f(osm);
    f.open(QFile::ReadOnly);
    if (f.error()){
        qDebug("%s:%d Cant open '%s' file. Remember to pass in the OSM file you want to convert",__FILE__,__LINE__,(char*)args.at(1).unicode());
        a.exit(1);
    }
    QXmlStreamReader xml(&f);

    CoordinateList coords;
    WayList ways;

    QTime t;

    t.start();
    readXML(xml, f, coords, ways);
    qDebug("%s:%d %d ms to load",__FILE__,__LINE__,t.elapsed());

    filterWays(ways);

    qDebug("%s:%d %d points",__FILE__,__LINE__,coords.count());
    qDebug("%s:%d %d ways",__FILE__,__LINE__,ways.count());

    t.start();
    KdNode kdtree(coords);
    qDebug("%s:%d %d ms to create tree",__FILE__,__LINE__,t.elapsed());

    qDebug("%s:%d coords %d points, kdtree %d points on %d nodes",__FILE__,__LINE__,coords.count(),kdtree.pointCount(),kdtree.nodeCount());

    int kdtreefilesize=kdtree.nodeCount()*4*3;
    qDebug("%s:%d kdtree size: %d",__FILE__,__LINE__,kdtreefilesize);

    bool ok;
    t.start();
    ok=kdtree.save("/tmp/kdtree.bin","/tmp/kddata.bin","/tmp/kdnames.bin");
    qDebug("%s:%d %d ms to save",__FILE__,__LINE__,t.elapsed());

    QRect bbox=kdtree.bounding();
    qDebug("%s:%d Boundingbox is %d,%d %d,%d",__FILE__,__LINE__,bbox.left(),bbox.top(),bbox.width(),bbox.height());

    if (ok)
        qDebug("%s:%d Saved OK",__FILE__,__LINE__);
    else{
        qDebug("%s:%d Error saving!",__FILE__,__LINE__);
        exit(1);
    }

    foreach(Way *w, ways){
        w->internalCheck();
    }
    /**
     * Unnecesary, but clean.. uncomment if you really want te be clean
    foreach(Way *w, ways){
        delete w;
    }
    */
}

/**
 * Reads the given XML, and adds to the coords and ways lists.
 *
 * TODO Celan spagetti
 */
void readXML(QXmlStreamReader &xml, QFile &f, CoordinateList &coords, WayList &ways){
        QXmlStreamReader::TokenType type;
    int count=0;
    bool isSorted=false;
    int npoints=0;
    float fsize=f.size()/100.0;
    while(!xml.atEnd()){
        type=xml.readNext();
        //qDebug("%s:%d %s %s",__FILE__,__LINE__,(char*)xml.tokenString().toAscii().data(),(char*)xml.name().toString().toAscii().data());
        if (type==QXmlStreamReader::StartElement){
            if (xml.name()=="node"){
                //qDebug("%s:%d %s %s",__FILE__,__LINE__,xml.attributes().value("lat").toString().toAscii().data(),xml.attributes().value("lon").toString().toAscii().data());
                coords.append(Coordinate(xml.attributes().value("id").toString().toDouble(),
                                         -xml.attributes().value("lat").toString().toDouble(),
                                         xml.attributes().value("lon").toString().toDouble()));
                isSorted=false;
                npoints++;
            }
            else if  (xml.name()=="way"){
                if (!isSorted){
                    qSort(coords.begin(), coords.end(), idLessThan);
                    isSorted=true;
                }
                type=xml.readNext();
                int nnodes=0;
                Way *way=new Way;
                while(xml.name()!="way" && !xml.atEnd()){
                    //qDebug("%s:%d %s %s",__FILE__,__LINE__,(char*)xml.tokenString().toAscii().data(),(char*)xml.name().toString().toAscii().data());
                    if (type==QXmlStreamReader::StartElement){
                        if (xml.name()=="nd"){
                            int nd=xml.attributes().value("ref").toString().toDouble();
                            CoordinateList::Iterator c=findCoordinate(coords,nd);
                            //qDebug("%s:%d new way point: %s",__FILE__,__LINE__,(char*)c->toString().unicode());
                            if (c==coords.end()){
                                qDebug("%s:%d not found coordinate %d!",__FILE__,__LINE__,nd);
                            }
                            else{
                                c->setWay(way);
                                way->addCoordinate(*c);
                                //qDebug("%s:%d found %d %s",__FILE__,__LINE__,c->getId(), (char*)c->toString().toUtf8().data());
                            }
                            nnodes++;
                        }
                        else if (xml.name()=="tag"){
                            if (xml.attributes().value("k")=="name")
                                way->setName(xml.attributes().value("v").toString());
                            if (xml.attributes().value("k")=="highway")
                                way->setType(xml.attributes().value("v").toString());
                            if (xml.attributes().value("k")=="railway")
                                way->setType(xml.attributes().value("v").toString());
                            if (xml.attributes().value("k")=="landuse")
                                way->setType(QString("landuse-%1").arg(xml.attributes().value("v").toString()));
                            if (xml.attributes().value("k")=="leisure")
                                way->setType(QString("leisure-%1").arg(xml.attributes().value("v").toString()));
                        }
                    }
                    type=xml.readNext();
                }
                //qDebug("%s:%d %s %s",__FILE__,__LINE__,(char*)xml.tokenString().toAscii().data(),(char*)xml.name().toString().toAscii().data());
                //way->setSkip(true);
                ways.append(way);
                //qDebug("%s:%d new way with %d nodes",__FILE__,__LINE__,nnodes);
            }
        }
        count++;
        if (count>2500000){
            count=0;
            qDebug("%s:%d %.2f%%",__FILE__,__LINE__,f.pos()/fsize);
        }
    }
}

/**
 * @short Basic filtering on what to show.
 *
 * Marks as skipable not wanted ways.
 */
void filterWays(WayList &wl){
    foreach(Way *w, wl){
        if (w->typeId()==254)    w->setSkip(true);
        //if (w->typeId()<32)   w->setSkip(true);
    }
}
