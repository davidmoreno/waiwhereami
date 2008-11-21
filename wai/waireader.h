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
#ifndef WAIREADER_H
#define WAIREADER_H

#include <QString>
#include <QRect>
#include <QFile>

class MapView;
class QPainter;
class StreetRenderer;

typedef signed int int32;

class WaiReader
{
public:
    WaiReader(const QString &kdtreefile, const QString &datafile, const QString &namesfile, MapView *parent);
    ~WaiReader();

    //QList<QPoint> getPointsInside(const QRect &);
    int drawObjectsInside(QPainter *painter, const QRect &r);
    int drawObjectsInsideRecursive(int32 mapPos, bool atLat, const QRect &sr);

    bool error(){ return hasErrors; }
protected:

    void setPenAndBrush(QPainter *painter, unsigned char type);


protected:
    bool hasErrors;

    QFile kdtree;
    QFile kddata;
    QFile kdnames;
    int32 *kdmap;
    unsigned char *mapdata;
    char *namesdata;
    MapView *mapview;
    StreetRenderer *renderer;

    /// @{ @name current drawing, not thread safe
    QRect drect;
    QPainter *dpainter;
    /// @}
};

#endif // WAIREADER_H
