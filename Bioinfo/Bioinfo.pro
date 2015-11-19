QT += core
QT -= gui

TARGET = Bioinfo
CONFIG += console
CONFIG -= app_bundle
CONFIG +=c++11

TEMPLATE = app

SOURCES += main.cpp \
    MapEdge.cpp \
    GraphReader.cpp \
    LayoutWriter.cpp \
    TransitiveEdgeRemover.cpp \
    DataBase.cpp

HEADERS += \
    MapEdge.h \
    GraphReader.h \
    LayoutWriter.h \
    TransitiveEdgeRemover.h \
    DataBase.h

