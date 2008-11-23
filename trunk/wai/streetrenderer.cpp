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

#include <stdlib.h>

#include "streetrenderer.h"
#include "waystyles.h"
#include "mapview.h"

StreetRenderer::StreetRenderer(MapView *_mapView, qint32 *_kdmap, unsigned char *_mapdata, char *_namesdata){
    mapView=_mapView;
    kdmap=_kdmap;
    mapdata=_mapdata;
    namesdata=_namesdata;
    drawNames=false;
    srand(time(NULL));
}

/**
 * @short sets the paitner for sucesive renderings.
 */
void StreetRenderer::setPainter(QPainter *_painter){
    painter=_painter;
    //painter->setRenderHint(QPainter::Antialiasing);
    areasPainted.clear();
    namesPainted.clear();
}

/**
 * @short Renders an area
 */
int StreetRenderer::render(unsigned int currentPos){
    /*
    {
        QBrush b=wayStyles[(rand()%4)+128].brush;
        //painter->setBrush(b);
        painter->fillRect(0,0,1024,768,b);
    }
    */
    int datapos=kdmap[currentPos+1];
    unsigned char nsegments=mapdata[datapos]+1;
    //qDebug("%s:%d %d segments",__FILE__,__LINE__,nsegments);
    datapos++;

    QPen black("#000000");

    QString name;
    unsigned char npoints;
    unsigned char type;
    unsigned int nameArea;
    QPolygon poly;
    QPoint P,Q;
    QPen mypen;
    for (int i=0;i<nsegments;i++){
        poly.clear();
        npoints=mapdata[datapos]+1;
        type=mapdata[datapos+1];
        nameArea=*((qint32*)(&mapdata[datapos+2]));

        if (type>127 && areasPainted.contains(nameArea)){
            datapos+=6+8*npoints;
            continue;
        }
        else
            areasPainted.insert(nameArea);

        mypen=wayStyles[type].pen;
        painter->setBrush(wayStyles[type].brush);

        //qDebug("%s:%d %d. %d points",__FILE__,__LINE__,i,npoints);
        qint32 *p=(qint32*)&mapdata[datapos+6];
        int points[npoints*2];
        int *ppoints=points;
        for (int j=0;j<npoints;j++){
            P.setX(*p);
            P.setY(*(p+1));
            Q=mapView->world2window(P);

            *ppoints=Q.x();
            *(ppoints+1)=Q.y();

            p+=2;
            ppoints+=2;
        }
        poly.setPoints(npoints,points);
        if (type>127 && type!=255){ // depending on type...
            //qDebug("%s:%d type %d",__FILE__,__LINE__, type);
            painter->setPen(mypen);
            painter->drawPolygon(poly,Qt::WindingFill);
        }
        else{
            if (wayStyles[type].drawBorder){
                black.setWidth(mypen.width()+2);
                painter->setPen(black);
                painter->drawPolyline(poly);
            }
            painter->setPen(mypen);
            painter->drawPolyline(poly);
        }

        if (drawNames){
            name=QString::fromUtf8(&namesdata[nameArea]);
            if (!namesPainted.contains(name)){
                painter->setPen(QPen());
                painter->drawText(poly[poly.count()/2],name);
                namesPainted.insert(name);
            }
        }

        datapos+=6+8*npoints;
    }
    //dpainter->drawPolygon(pointList,nr);

    return nsegments;
}
