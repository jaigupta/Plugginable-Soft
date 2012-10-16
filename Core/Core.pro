#-------------------------------------------------
#
# Project created by QtCreator 2011-10-26T22:17:47
#
#-------------------------------------------------

QT       += core gui

TARGET = Core
TEMPLATE = app


SOURCES += main.cpp\
    cproject.cpp \
    loggerwindow.cpp

HEADERS  += \
    cproject.h \
    loggerwindow.h

FORMS    += mainwindow.ui \
    loggerwindow.ui

LIBS += -L../libs -lcommonLibs

INCLUDEPATH += ../libs
