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
#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QWidget>
#include <QList>

#include "wayinfo.h"

class WaiReader;

/**
 * @short Widget that allow to see maps.
 */
class MapView : public QWidget
{
    Q_OBJECT
public:
    MapView(QWidget *parent=NULL);

    bool addMap(const QString &kdtreefile, const QString &datafile, const QString &namesfile, int min, int max);

    WayInfo getWayInfoAt(const QPoint &);

    /// @{ @name Window<->world<->meters conversion routines
    QPoint window2world(const QPoint &) const;
    QPoint world2window(const QPoint &) const;

    QRect window2world(const QRect &) const;
    QRect world2window(const QRect &) const;
    QSize worldWindowSize() const{ return worldWindow.size(); }

    QSizeF window2meters(const QSize &) const;
    /// @}

signals:
    /// Clicked at that world position
    void clicked(const QPoint &);

protected:
    void paintEvent(QPaintEvent *paint);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void wheelEvent ( QWheelEvent * event );

    /// Rect for the data that is shown at this widget.
    QRect worldWindow;

    /// Maps known by this mapview.
    QList<WaiReader*> maps;

    /// Position for the last mouse press/move, to move the map
    QPoint lastMouseMovePosition;
    /// True at release time if there was a movement
    bool lastMousePressWasMovement;
};

#endif // MAPVIEW_H
