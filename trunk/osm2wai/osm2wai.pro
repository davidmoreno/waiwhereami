# -------------------------------------------------
# Project created by QtCreator 2008-11-06T19:55:08
# -------------------------------------------------
QT += xml
QT -= gui
TARGET = osm2wai
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    coordinate.cpp \
    kdnode.cpp \
    ../../../../osm/wai/osm2wai/way.cpp
OTHER_FILES += FORMAT.txt
HEADERS += coordinate.h \
    kdnode.h \
    ../../../../osm/wai/osm2wai/way.h
