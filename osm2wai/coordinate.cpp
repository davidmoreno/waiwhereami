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
#include <stdlib.h>

#include "coordinate.h"
#include "way.h"

#define DEGRESS(x) (int(x))
#define MINUTES(x) (abs(fmod(x,1)*60))
#define SECONDS(x) (fabs(fmod(x*60,1)*60))


/**
 * @short Shows a coordinate in pretty degress, minutes, seconds...
 */
QString Coordinate::toString(){
    return QString("%1:%2:%3 %4:%5:%6 ").
              arg(DEGRESS(data->lat)).arg(MINUTES(data->lat)).arg(SECONDS(data->lat)).
              arg(DEGRESS(data->lon)).arg(MINUTES(data->lon)).arg(SECONDS(data->lon));
}

/**
 * @short Returns the latitude as an int, with mercantor proyection.
 */
int Coordinate::intLatitude(){
    return ((data->lat/180.0)/111.0)*0x7FFFFFFF;
}

/**
 * @short Returns the longitude as an int, with mercantor proyection.
 */
int Coordinate::intLongitude(){
    return ((data->lon/180.0)/111.0)*0x7FFFFFFF;
}


/**
 * @short X using mercator projection
 *
 * http://en.wikipedia.org/wiki/Mercator_projection
 */
double Coordinate::mercatorX(){
    return data->lon;
}
/**
 * @short Y using mercator projection
 *
 * http://en.wikipedia.org/wiki/Mercator_projection
 */
double Coordinate::mercatorY(){
    double l=data->lat*M_PI/180.0;
    return log(tan(l)+(1.0/cos(l)))*180.0/M_PI;
}

/**
 * @short X using mercator projection, integer return
 *
 * http://en.wikipedia.org/wiki/Mercator_projection
 */
int Coordinate::intMercatorX(){
    return ((mercatorX()/180.0)/111.0)*0x7FFFFFFF;
}

/**
 * @short X using mercator projection, integer return
 *
 * http://en.wikipedia.org/wiki/Mercator_projection
 */
int Coordinate::intMercatorY(){
    return ((mercatorY()/180.0)/111.0)*0x7FFFFFFF;
}

/**
 * @short Sets the map
 *
 * const is nt real! I don't know why, if not const at main.cpp it does not compile an iterator.
 */
void Coordinate::setWay(Way *w) const{
    data->way.append(w);
}
/*
bool Coordinate::isAtWay(Way *w) const{
    return way.contains(w);
}
*/
WayList Coordinate::getWay() const{
    return data->way;
}

/// Used to order by id
bool idLessThan(Coordinate &a, Coordinate &b){
    return a.getId()<b.getId();
}
/*
/// Used to order by wayid
bool wayIdLessThan(Coordinate &a, Coordinate &b){
    return a.getWayId()<b.getWayId();
}
*/
/// Used to order by latitude
bool latitudeLessThan(Coordinate &a, Coordinate &b){
    return a.latitude()<b.latitude();
}
/// Used to order by longitude
bool longitudeLessThan(Coordinate &a, Coordinate &b){
    return a.longitude()<b.longitude();
}


/**
 * @short Hash value for coordinates.
 */
uint qHash(const Coordinate &c){
    return qHash(c.getId());
}

/**
 * @short Searchs a coordinate by id, and returns the reference.
 *
 * TODO: Fix bin search, it needs a hack after.. silly iterators...
 */
CoordinateList::Iterator findCoordinate(CoordinateList &list, int id){
    CoordinateList::Iterator a=list.begin();
    CoordinateList::Iterator b=list.end()-1;
    int mid=list.count();
    int cid;
    CoordinateList::Iterator midI;

    while(a!=b && mid>1){
        //qDebug("%s:%d find binary %d<%d<%d (%d)",__FILE__,__LINE__,a->getId(), id, b->getId(),mid);
        mid=mid/2;
        midI=a+mid;
        cid=midI->getId();
        if (cid>id)
            b=midI;
        else if (cid<id)
            a=midI;
        else if (cid==id)
            return midI;
        else
            return list.end();
    }
    while(a!=b){
        //qDebug("%s:%d find binary %d<%d<%d (%d)",__FILE__,__LINE__,a->getId(), id, b->getId(),-1);
        if (a->getId()==id)
            return a;
        ++a;
    }
    if (b->getId()==id)
        return b;
    return list.end();
}


/**
 * @short Searchs a coordinate by id, and returns the reference, o a set
 *
 */
CoordinateSet::Iterator findCoordinate(CoordinateSet &set, int id){
    Coordinate c(id,0,0);
    return set.find(c);
}
