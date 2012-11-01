#-------------------------------------------------
#
# Project created by QtCreator 2012-11-02T00:13:33
#
#-------------------------------------------------

QT       += script

QT       -= gui

TARGET = ../../$$qtLibraryTarget(ScriptLoadHelpers)
TEMPLATE = lib

CONFIG += debug_and_release build_all

DEFINES += SCRIPTLOADHELPERS_LIBRARY

SOURCES += scriptenginesingle.cpp

HEADERS += scriptenginesingle.h\
        ScriptLoadHelpers_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

HEADERS += \
    seinvoker.h

SOURCES += \
    seinvoker.cpp
