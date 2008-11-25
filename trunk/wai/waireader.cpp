/**
  *  WAI -- Where am I?
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

#include <QPainter>
#include <QFile>

#include "waireader.h"
#include "mapview.h"
#include "streetrenderer.h"

WaiReader::WaiReader(const QString &kdtreefile, const QString &datafile, const QString &namesfile, MapView *parent) : mapview(parent)
{
    kdtree.setFileName(kdtreefile);
    if (!kdtree.open(QFile::ReadOnly)){
        qDebug("%s:%d Can open file %s",__FILE__,__LINE__,(char*)kdtreefile.toUtf8().data());
        hasErrors=true;
        return;
    }
    kdmap=(int32*)kdtree.map(0,kdtree.size());

    kddata.setFileName(datafile);
    if (!kddata.open(QFile::ReadOnly)){
        qDebug("%s:%d Can open file %s",__FILE__,__LINE__,(char*)datafile.toUtf8().data());
        hasErrors=true;
        return;
    }
    mapdata=(unsigned char*)kddata.map(0,kddata.size());

    kdnames.setFileName(namesfile);
    if (!kdnames.open(QFile::ReadOnly)){
        qDebug("%s:%d Can open file %s",__FILE__,__LINE__,(char*)namesfile.toUtf8().data());
        hasErrors=true;
        return;
    }
    namesdata=(char*)kdnames.map(0,kdnames.size());


    hasErrors=false;
    renderer=new StreetRenderer(parent, kdmap, mapdata, namesdata);
}

WaiReader::~WaiReader(){
    delete renderer;
}


/**
 * @short Given those parameters, it draws everything it has to draw on this sector.
 *
 * @param painter  Painter where to draw
 * @param r        World rect to draw
 *
 * Actually it starts the finding of areas, and for the matching areas, the roads are drawn. this methods are not thread
 * safe in no way; They have even global data (should be no issue since Qt draw operations are always performed at the
 * same thread).
 *
 * Returns the informative number of points drawn.
 */
int WaiReader::drawObjectsInside(QPainter *painter, const QRect &r){
    dpainter=painter;
    drect=r;

    //qDebug("%s:%d    draw (%d,%d) to (%d,%d)",__FILE__,__LINE__,r.left(), r.top(), r.right(), r.bottom());

    renderer->setPainter(painter);

    return drawObjectsInsideRecursive(0,true,drect);
}




/**
 * @short Given those parameters, it draws everything it has to draw on this sector.
 *
 * @param currentPos  Current offset at the kdmap.
 * @param atLat       Kd binary tree alternates between latitude and longitude
 * @param worldRect   The current worldRect to draw, to ease and optimize later usage.
 *
 * Actually it starts the finding of areas, and for the matching areas, the roads are drawn.
 *
 * This is the real worker, and it is used recursively.
 *
 * Returns the informative number of points drawn.
 */
int WaiReader::drawObjectsInsideRecursive(int32 currentPos, bool atLat, const QRect &worldRect){

    //static QPoint pointList[256];
    bool less, more;
    qint32 current=kdmap[currentPos];
    if (current){ // Must continue looking inside, not a leaf node
        if (atLat){
            less=current>=drect.top();
            more=current<=drect.bottom();
            if (more && !less)
                current=drect.top();
            if (less && !more)
                current=drect.bottom();
            //qDebug("%s:%d %d<%d<%d (%d %d)",__FILE__,__LINE__,drect.top(),current,drect.bottom(), less,more);
        }
        else{
            less=current>drect.left();
            more=current<=drect.right();
            //qDebug("%s:%d %d<%d<%d (%d %d)",__FILE__,__LINE__,drect.left(),current,drect.right(), less,more);
            if (more && !less)
                current=drect.left();
            if (less && !more)
                current=drect.right();
        }

/*
        {
            QRect r=worldRect;
            r=mapview->world2window(r);
            qDebug("%s:%d    draw (%d,%d) to (%d,%d) l %d m %d",__FILE__,__LINE__,r.left(), r.top(), r.right(), r.bottom(), less, more);
        }
*/
        /// positions are divided by 4, as they are in bytes, and my array is in int32
        int ret=0;
        if (less){
            QRect r=worldRect;
            if (atLat)
                r.setBottom(current);
            else
                r.setRight(current);
            ret=drawObjectsInsideRecursive(kdmap[currentPos+1]>>2, !atLat, r);
        }
        if (more){
            QRect r=worldRect;
            if (atLat)
                r.setTop(current);
            else
                r.setLeft(current);
            ret+=drawObjectsInsideRecursive(kdmap[currentPos+2]>>2, !atLat, r);
        }

        return ret;
    }
    else{ // ok, leaf node, draw
        //qDebug("%s:%d draw    (%d,%d) to (%d,%d)",__FILE__,__LINE__,worldRect.left(), worldRect.top(), worldRect.right(), worldRect.bottom());
        //QRect r=mapview->world2window(worldRect);
        //qDebug("%s:%d    draw (%d,%d) to (%d,%d)",__FILE__,__LINE__,r.left(), r.top(), r.right(), r.bottom());
        //dpainter->setClipRect(r);
        return renderer->render(currentPos);
    }
}
