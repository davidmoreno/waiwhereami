# Introduction #

This is a small howto on how to use WaI!

## Download & Compile ##

First of all, download and compile. To download you can go to the Source tab, and download using subversion. To compile use the following commands at the osm2wai and wai subdirectories.

```
qmake-qt4 && make 
```


## Get your mapa data ##

Now you need an OSM XML file. Normally you would think about using the world map. Now think twice. Althought the idea is highly attractive, its a HUGE data file, most probably you dont need all the world, and finally the OSM2WAI converted would need a LOT of RAM to perform the translation, as everything is loaded at mem. So the best you can do is download a local area map. At http://downloads.cloudmade.com/ you can download maps by continent, country, state... I usually use the spain.osm map, as I live on spain.

## Generate the WaI! files ##

Now you can generate the WaI! files. You can generate just one WaI! file, with all the data, and ue that map, but usually you would prefer the other option, generate several WaI! files for different zoom levels.

For the first, just call:

```
./osm2wai $PATH_TO_OSM
```

You can add more advanced options, that can be viewed with `--help`.

If you want to generate several WaI! files, you can use the `preparemaps.sh` script that with a OSM file, and a path, it generates a meta file with the layered maps:

```
./preparemaps.sh /tmp/spain.osm /tmp/layers/
```

## View the maps ##

To view your maps there are three options; with no command line parameters, it loads the maps at /tmp/ (the default dir for no `--name` option on the converter). You can also pass several WaI! map directories, each with a layer, rendered in the same order as passed (last map will be draw last, and will be fully seen, like painters algorithm).

Finally you can pass a WaiMetaMap file that has information on where to find the maps, and on which zoom levels to use it. You can pass the WaiMetaMap file with the `--meta` option:

```
./wai --meta /tmp/layers/
```

## Final words ##

The initial area that is shown is my neighborhood, so if you don't use the Spanish map, you will not see anything. When you convert an OSM file the bounding rect for that area is printed to the console; you can use that area and set it at the waimap.cpp file, at the WaiMap constructor, to start on a given area.