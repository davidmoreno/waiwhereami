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

#ifndef COORDINATE_H
#define COORDINATE_H

#include <QString>
#include <QList>
#include <QSet>
#include <QExplicitlySharedDataPointer>
#include <QSharedData>

class Way;

typedef QList<Way*> WayList;


/**
 * @short Privated shared data for the coordinates
 */
class CoordinateData : public QSharedData{
    public:
        CoordinateData(int id, double lat, double lon):id(id), lat(lat),lon(lon) {  }
        int id;
        double lat;
        double lon;
        WayList way;
};

/**
 * @short A GPS coordinate
 */
class Coordinate
{
public:
    Coordinate(int id, double lat, double lon): data(new CoordinateData(id, lat,lon)) {  }

    QString toString();

    int getId() const { return data->id; }
    //bool isAtWay(Way *) const;
    double latitude() const { return data->lat; }
    double longitude() const { return data->lon; }

    int intLongitude();
    int intLatitude();

    double mercatorX();
    double mercatorY();

    int intMercatorX();
    int intMercatorY();

    void setWay(Way *w) const;
    WayList getWay() const;

    bool operator==(const Coordinate &other) const { return data->id==other.data->id; }
    bool operator!=(const Coordinate &other) const { return data->id!=other.data->id; }

protected:
    QExplicitlySharedDataPointer<CoordinateData> data;
};

typedef QList<Coordinate> CoordinateList;
typedef QSet<Coordinate> CoordinateSet;

/// Used to order by id
bool idLessThan(Coordinate &a, Coordinate &b);
/// Used to order by longitude
//bool wayIdLessThan(Coordinate &a, Coordinate &b);
/// Used to order by latitude
bool latitudeLessThan(Coordinate &a, Coordinate &b);
/// Used to order by longitude
bool longitudeLessThan(Coordinate &a, Coordinate &b);
/// Finds a coordinate by id
CoordinateList::Iterator findCoordinate(CoordinateList &list, int id);
/// Finds a coordinate by id, on a set
CoordinateSet::Iterator findCoordinate(CoordinateSet &set, int id);
/// Hash for coordinates.
uint qHash(const Coordinate &c);

#endif // COORDINATE_H
