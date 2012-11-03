#-------------------------------------------------
#
# Project created by QtCreator 2012-10-20T05:50:53
#
#-------------------------------------------------

include(../QScriptGuide.pri)

TARGET = QtScriptDemo
TEMPLATE = app

INCLUDEPATH += ../ScriptLoadHelpers
LIBS += -L../ -lScriptLoadHelpers

SOURCES += main.cpp\

FORMS    += \
    ui/form.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    js/script.js
