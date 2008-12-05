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

#ifndef WAYINFO_H
#define WAYINFO_H

#include <QString>

/**
 * @short A collection on information about a given way.
 */
struct WayInfo
{
    WayInfo();
    WayInfo(const QString &name, unsigned char type);

    QString name;
    unsigned char type;
    QString extraInfo;
    unsigned int pointCount;

    QString typeDescription();
};

#endif // WAYINFO_H
