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

#include <QMessageBox>

#include "waiwindow.h"
#include "mapview.h"
#include "waireader.h"


WaiWindow::WaiWindow(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    mapview=new MapView(this);

    connect(mapview,SIGNAL(clicked(const QPoint &)),
            this,   SLOT(showInfoAt(const QPoint &)));

    setCentralWidget(mapview);
}

WaiWindow::~WaiWindow()
{

}

/**
 * @short Makes the map view load the maps at that ubication.
 *
 * Can be called several times, and each map will be loaded. The will be drawn in the same order, so you may
 * pass the layers you want to be bellow the firsts.
 */
void WaiWindow::addMap(QString dir, int min, int max){
    bool ok=mapview->addMap(QString("%1/kdtree.bin").arg(dir), QString("%1/kddata.bin").arg(dir), QString("%1/kdnames.bin").arg(dir), min, max);
    if (! ok) {
        qDebug("%s:%d error adding map",__FILE__,__LINE__);
        return;
    }
}

/**
 * @short Shows information at that point.
 *
 * It gets the point (should be segment) closer to that point, and
 * shows all relevant information known.
 */
void WaiWindow::showInfoAt(const QPoint &p){
    qDebug("%s:%d get info at point %d,%d",__FILE__,__LINE__,p.x(),p.y());

    WayInfo info=mapview->getWayInfoAt(p);

    QMessageBox::information(this, tr("Way information"),
                             tr("<h1>%1</h1>\n"
                                "<h2>%2</h2>\n"
                                "%3 points").arg(info.name).
                                             arg(info.typeDescription()).
                                             arg(info.pointCount));
}

