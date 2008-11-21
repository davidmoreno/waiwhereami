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

#ifndef KDNODE_H
#define KDNODE_H

#include <QRect>

#define MAX_AT_BUCKET 150

#include "coordinate.h"


class QFile;
class Way;

/**
 * @short A KdTree for the given coordinate list
 *
 * It is a binary tree alternating longitude and latitude as keys. root is always latitude.
 *
 * http://en.wikipedia.org/wiki/Kd_tree
 */
class KdNode
{
public:
    KdNode(CoordinateList l);
    ~KdNode();

    bool save(const QString &treefile, const QString &datafile, const QString &namefile);

    int nodeCount();
    int pointCount();
    int keyAsInt();
    QRect bounding(){ return QRect(QPoint(boundingBox[0],boundingBox[2]),QPoint(boundingBox[1],boundingBox[3])); }
protected:
    KdNode(CoordinateList::Iterator begin, CoordinateList::Iterator end, int count, bool atLatitude){ prepareNode(begin,end,count,atLatitude); }
    void prepareNode(CoordinateList::Iterator begin, CoordinateList::Iterator end, int count, bool atLatitude);

    int save(qint32 *tree, QFile &data, QFile &nameData, int &currentPos);
    void saveData(QFile &data, QFile &nameData);
    int saveNameData(Way *, QFile &data);
    CoordinateList getCoordinatesAtWay(const CoordinateList &coords, Way *way);

    double key;
    CoordinateList list;
    KdNode *less;
    KdNode *more;

    static int boundingBox[4];
};

#endif // KDNODE_H
