#-------------------------------------------------
#
# Project created by QtCreator 2011-10-26T22:35:16
#
#-------------------------------------------------

TARGET        = $$qtLibraryTarget(timerPlugin)

TEMPLATE = lib

CONFIG       += plugin

QT += core gui

SOURCES += main.cpp\
        firstplugin.cpp \
    dialog.cpp \
    datastore.cpp \
    abell.cpp

HEADERS  += firstplugin.h \
    dialog.h \
    datastore.h \
    abell.h

FORMS    += firstplugin.ui \
    dialog.ui \
    abell.ui

INCLUDEPATH +=../Core

DESTDIR       = ../Core-build-desktop/plugins
