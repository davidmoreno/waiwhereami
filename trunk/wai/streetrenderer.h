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

#ifndef STREETRENDERER_H
#define STREETRENDERER_H

#include <QPainter>
#include <QSet>

class MapView;

/**
 * @short Specialized class that 'just' draws a small area from the kdmap and mapdata
 *
 * It is a specialized class so it can be later reimplemented to have several available
 * renderers.
 */
class StreetRenderer
{
public:
    StreetRenderer(MapView *mapView, qint32 *kdmap, unsigned char *mapdata,  char *namesdata);
    void setPainter(QPainter *);
    int render(unsigned int currentPos);
protected:
    qint32 *kdmap;
    unsigned char *mapdata;
    char *namesdata;
    MapView *mapView;
    QPainter *painter;
    bool drawNames;
    // Zoom ranges allowed, 0 is off.
    int min, max;

    QSet<int> areasPainted;
    QSet<QString> namesPainted;
};

#endif // STREETRENDERER_H
