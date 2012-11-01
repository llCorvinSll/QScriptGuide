#-------------------------------------------------
#
# Project created by QtCreator 2012-10-20T05:50:53
#
#-------------------------------------------------

include(../QScriptGuide.pri)

TARGET = QtScriptDemo
TEMPLATE = app


SOURCES += main.cpp\
    src/invoker.cpp

HEADERS  += \
    src/invoker.h

FORMS    += \
    ui/form.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    js/script.js

HEADERS += \
    src/uildinvoker.h

SOURCES += \
    src/uildinvoker.cpp
