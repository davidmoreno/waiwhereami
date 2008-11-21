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
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifndef WAY_H
#define WAY_H

#include <QList>
#include <QSet>

class QFile;

#include "coordinate.h"

class Way
{
public:
    Way();
    void setName(const QString &_name){ name=_name; }
    void setType(const QString &_type){ type=_type; }
    void setSkip(bool _skip){ skip=_skip; }
    void setLanes(int _lanes){ lanes=_lanes;       }
    void setOneWay(bool _oneway){ oneway=_oneway;  }

    int getId() const { return id; }
    int getSkip() const { return skip; }
    QString getName() const { return name; }
    void saveData(QFile &namefile);
    quint32 getNamePos(){ return namepos; }
    /// Adds a coordinate to the way. Coordinates MUST be inserted in order.
    void addCoordinate(const Coordinate &c){ coords.append(c); }
    CoordinateList getCoordinateList(){ return coords; }
    void useCoordinate(const Coordinate &c){ coordsOnMap.insert(c.getId()); }

    bool internalCheck();

    unsigned char typeId();
protected:
    unsigned char typeIdCache;
    bool skip;
    QString name;
    QString type;
    int lanes;
    bool oneway;
    int id;
    quint32 namepos;

    QSet<int> coordsOnMap;
    CoordinateList coords;
};

typedef QList<Way*> WayList;

bool typeIdGreaterThan(Way *a, Way *b);
bool typeIdLessThan(Way *a, Way *b);

#endif // WAY_H
