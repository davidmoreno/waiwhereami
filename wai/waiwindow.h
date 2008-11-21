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
#ifndef WAIWINDOW_H
#define WAIWINDOW_H

#include <QtGui/QMainWindow>

class MapView;

class WaiWindow : public QMainWindow
{
    Q_OBJECT

public:
    WaiWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~WaiWindow();
protected:
    MapView *mapview;
};

#endif // WAIWINDOW_H
