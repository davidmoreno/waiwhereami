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

#include <stdlib.h>

#include <QPainter>
#include <QPaintEvent>
#include <QTime>

#include "mapview.h"
#include "waireader.h"

MapView::MapView(QWidget *parent):QWidget(parent)
{
    /*
    worldWindow=QRect(429926, -32244,  /// 40º, -3º
                      10748160, 10748160); /// +10º, +10º
                      */
    // experimental value.. I dont really know where is it, but there is something.
    //worldWindow=QRect(4765996,-393350, 1627,1533);
    //worldWindow=QRect(4152380,-999694,1093378,1465056);
    //worldWindow=QRect(-395223,4759429,13163,15369);
    worldWindow=QRect(-395223,-4774797,13163,15369);
    //worldWindow=QRect(-999694,-5245757,1465056,1093378);
    worldWindow=QRect(-393350,-4352265,1533,1237);
}

/**
 * @short Adds a map to the list of known maps.
 */
bool MapView::addMap(const QString &kdtreefile, const QString &datafile, const QString &namesfile){
    WaiReader *reader=new WaiReader(kdtreefile, datafile, namesfile, this);
    if (reader->error()){
        delete reader;
        return false;
    }
    maps.append(reader);
    return true;
}

/**
 * @short Converts a window point to a world coordinate
 *
 * It s a simple rule of three ( http://en.wikipedia.org/wiki/Rule_of_three_(mathematics) ),
 * but as I can not overflow, it gets a little bit more complicated.
 *
 * TODO: Overflow check, if overflows use the other more costly algorithm (something like decomposition..)
 */
QPoint MapView::window2world(const QPoint &p) const{
    int x=(p.x()*worldWindow.width())/width() + worldWindow.x();
    int y=(p.y()*worldWindow.height())/height() + worldWindow.y();

    return QPoint(x,y);
}
/**
 * @short Converts from the world coordinate to a window coordinate
 * @see window2world
 */
QPoint MapView::world2window(const QPoint &p) const{
    int left=worldWindow.left();
    int top=worldWindow.top();
    int x=(p.x()-left)*width() / (worldWindow.right()-left);
    int y=(p.y()-top)*height() / (worldWindow.bottom()-top);
    return QPoint(x,y);
}
/**
 * @short Converts from the window coordinate to a world coordinate
 * @see window2world
 */
QRect MapView::window2world(const QRect &r) const{
    return QRect(window2world(r.topLeft()), window2world(r.bottomRight()));
}
/**
 * @short Converts from the world coordinate to a window coordinate
 * @see window2world
 */
QRect MapView::world2window(const QRect &r) const{
    return QRect(world2window(r.topLeft()), world2window(r.bottomRight()));
}

/**
 * @short Grabs mouse movements to move the map.
 */
void MapView::mouseMoveEvent(QMouseEvent * event){
    QPoint np=event->pos();

    QPoint nn=lastMouseMovePosition-np;
    //qDebug("%s:%d move %d %d",__FILE__,__LINE__,nn.x(), nn.y());
    nn=QPoint(nn.x()*worldWindow.width()/width(),
              nn.y()*worldWindow.height()/height());
    //qDebug("%s:%d move %d %d",__FILE__,__LINE__,nn.x(), nn.y());
    worldWindow.translate(nn);

    lastMouseMovePosition=np;
    update();
}

/**
 * @short Sets the initial movement point, to ease movement, sets the cursor.
 */
void MapView::mousePressEvent(QMouseEvent * event){
    lastMouseMovePosition=event->pos();
    setCursor(Qt::SizeAllCursor);
}

/**
 * @short Unsets the cursor.
 */
void MapView::mouseReleaseEvent(QMouseEvent * event){
    lastMouseMovePosition=event->pos();
    setCursor(Qt::ArrowCursor);
}

/**
 * @short Zooms in or out from a position
 */
void MapView::wheelEvent ( QWheelEvent * event ){
    int d;
    if (event->delta()>0)
        d=9;
    else
        d=11;

    QPoint mouseIsAt=window2world(event->pos());
    QPoint dif=mouseIsAt-worldWindow.topLeft();

    worldWindow=QRect(mouseIsAt,QSize(worldWindow.width()*d/10, worldWindow.height()*d/10));

    dif=QPoint(dif.x()*d/10, dif.y()*d/10);
    dif=mouseIsAt-dif;
    worldWindow.moveTo(dif);

    update();
}

/**
 * @short Draws the map, but only the modified part.
 *
 * TODO: Benchmark real work usage changing WaiReader/rects loop nesting.
 */
void MapView::paintEvent(QPaintEvent *paintEvent){
    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing);

    QRect wrect;

    QTime t;
    t.start();

    int totaldrawn=0;
    foreach(WaiReader *map, maps){
        foreach(QRect rect, paintEvent->region().rects()){
            wrect=window2world(rect);
            totaldrawn+=map->drawObjectsInside(&painter, wrect);
        }
    }
    qDebug("%s:%d Drawn %d objects (%d ms)",__FILE__,__LINE__,totaldrawn,t.elapsed());
}
