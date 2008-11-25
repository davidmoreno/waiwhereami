#!/bin/bash

echo "Dirty (and slow) OSM to Wai layered maps. See $0 file for layering options"

if [ -z "$2" ]; then
    echo "I need an OSM fila and an output directory where the layers will be placed: $0 <OSMFILE.osm> <OUTDIR>"
    exit 1
fi

mkdir -p $2

WAIMETAMAP=$2/waimetamap

./osm2wai --skip 30-256 --name $2/basestreets $1
./osm2wai --skip 1-30,60-256 --name $2/basestreets2 $1
./osm2wai --skip 0-60,128-256 --name $2/roads $1
./osm2wai --skip 0-128,200-255 --name $2/baseareas $1
./osm2wai --skip 0-200 --name $2/areas $1

rm -f $WAIMETAMAP

echo $2/areas - >> $WAIMETAMAP
echo $2/baseareas -20000 >> $WAIMETAMAP
echo $2/roads - >> $WAIMETAMAP
echo $2/basestreets -10000 >> $WAIMETAMAP
echo $2/basestreets2 -10000 >> $WAIMETAMAP

echo "DONE"

