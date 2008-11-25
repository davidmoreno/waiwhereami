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

#include <QFile>

#include "way.h"


static int way_id_counter=0;

Way::Way()
{
    id=way_id_counter++;
    type="unknown";
    lanes=1;
    oneway=false;
    skip=false;
    namepos=0;
    typeIdCache=0;
}

/**
 * @short Returns a type Id according to the parameters set on FORMAT.txt
 */
unsigned char Way::typeId(){
    if (typeIdCache)
        return typeIdCache;
    bool isArea=(coords.first()==coords.last());
    /*
    if (coords.first()==coords.last())
        qDebug("%s:%d closed area! %s",__FILE__,__LINE__,(char*)type.toUtf8().data());
    */
    if ((type=="pedestrian" || type=="footway") && !isArea)
        typeIdCache=1;
    else if (type=="cycleway")
        typeIdCache=2;
    else if (type=="steps")
        typeIdCache=3;
    else if (type=="footway" || type=="path")
        typeIdCache=3;
    else if (type=="residential" || type=="unclassified"  || type=="living_street"  || type=="narrow_gauge" || type=="motorroad")
        typeIdCache=8+(lanes%8); // simgle road, 1 lane
    else if (type=="road" || type=="secondary" || type=="tertiary"  || type=="secondary_link" || type=="tertiary_link" || type=="byway")
        typeIdCache=16+(lanes%4); // 8 is tertiary, + nr lanes.
    else if (type=="trunk" || type=="trunk_link")
        typeIdCache=20+(lanes%4);
    else if (type=="light_rail" || type=="rail" || type=="subway" || type=="tram")
        typeIdCache=24;
    else if (type=="motorway" || type=="motorway_link" || type=="primary" || type=="primary_link" || type=="raceway" || type=="motorway_junction")
        typeIdCache=32+(lanes%8); // 8 is tertiary, + nr lanes.
    else if (type=="service")
        typeIdCache=40+(lanes%8);
    else if (type=="viaduct")
        typeIdCache=48+(lanes%8);
    else if (type=="track" || type=="narrow-gauge")
        typeIdCache=56+(lanes%4);
    else if (type=="landuse-residential")
        typeIdCache=128;
    else if (type=="landuse-recreation_ground" || type=="pedestrian")
        typeIdCache=129;
    else if (type=="leisure-park" || type=="leisure-pitch" || type=="leisure-garden")
        typeIdCache=130;
    else if (type=="leisure-playground")
        typeIdCache=131;
    else if (type=="landuse-village_green")
        typeIdCache=132;
    else if (type=="landuse-commercial" || type=="leisure-sports_centre" || type=="landuse-retail" || type=="leisure-golf_course"  || type.startsWith("leisure") )
        typeIdCache=133;
    else if (type=="landuse-industrial")
        typeIdCache=134;
    else if (type=="landuse-military")
        typeIdCache=135;
    else if (type=="construction")
        typeIdCache=136;
    else if (type=="abandoned")
        typeIdCache=137;
    else if (type.startsWith("landuse") )
        typeIdCache=254;
    else{
        typeIdCache=255;
        if (type!="unknown")
            qDebug("%s:%d unknown type '%s'",__FILE__,__LINE__,(char*)type.toUtf8().data());
    }
    return typeIdCache;
}

/**
 * Saves all relevant data about this way.
 */
void Way::saveData(QFile &data){
    if (namepos==0){ // do not repeat saving...
        //qDebug("%s:%d save '%s' %ld",__FILE__,__LINE__,(char*)name.toUtf8().data(), (long int)data.pos());
        namepos=data.pos();
        data.write(name.toUtf8());
        data.write("",1);
    }
    else{
        //qDebug("%s:%d already saved at '%s' %d",__FILE__,__LINE__,(char*)name.toUtf8().data(),namepos);
    }
}

/**
 * @short Performs the internal check that all points are on the map, and no one is left.
 */
bool Way::internalCheck(){
    if (skip)
        return 0;
    int count=0;
    Coordinate lastlost=coords[0];
    foreach(Coordinate c,coords){
        if (!coordsOnMap.contains(c.getId())){
            count++;
            lastlost=c;
        }
    }
    if (count){
        qDebug("%s:%d %d/%d points missing at %s (%d) (last lost was %d)",__FILE__,__LINE__, count, coords.count(), (char*)name.toUtf8().data(), id, lastlost.getId());
    }
    return count;
}


/// Used to order by longitude
bool typeIdLessThan(Way *a, Way *b){
    return a->typeId()<b->typeId();
}

/// Used to order by longitude
bool typeIdGreaterThan(Way *a, Way *b){
    return a->typeId()>b->typeId();
}

