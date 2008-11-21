#!/bin/bash

if [ -z "$1" ]; then
  echo I need an osm file
  exit 1
fi

echo "data=[" > data.py
grep " lat=" "$1" | sed 's/.*lat="\(.*\)" lon="-*\([0-9]*\.[0-9]*\)".*/(\1,\2),/g' | grep -v node >> data.py
echo "]" >> data.py