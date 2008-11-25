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

#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>

#include "waiwindow.h"

void loadStateFile(const QString &metafile, WaiWindow *w);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WaiWindow w;
    bool state=0;

    foreach(QString dir, a.arguments().mid(1)){
        if (state==0){
            if (dir=="--meta")
                state=1;
            else
                w.addMap(dir);
        }
        else if (state==1){
            loadStateFile(dir, &w);
        }
    }
    if (a.arguments().count()==1){
        w.addMap("/tmp/");
    }

    w.show();
    return a.exec();
}

/**
 * @short Loads a meta maps file
 *
 * the format is just the directory with the map, and the zoom levels allowed.
 * the zoom levels are in the form 'min-max' where any of these may be missing.
 */
void loadStateFile(const QString &metafile, WaiWindow *w){
    QFile f(metafile);
    if (!f.open(QFile::ReadOnly)){
        qDebug("%s:%d error opening %s",__FILE__,__LINE__,(char*)metafile.toUtf8().data());
        return;
    }
    QTextStream fs(&f);
    QString l;
    QString dir;
    int min;
    int max;
    while(!fs.atEnd()){
        l=fs.readLine();
        min=0;
        max=0;

        dir=l.section(' ',0,0);
        min=l.section(' ',1,1).section('-',0,0).toInt();
        max=l.section(' ',1,1).section('-',1,1).toInt();
        qDebug("%s:%d read %s %d-%d",__FILE__,__LINE__,(char*)dir.toUtf8().data(), min, max);
        w->addMap(dir,min,max);
    }
}
