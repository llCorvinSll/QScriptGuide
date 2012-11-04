include(../QScriptGuide.pri)

TARGET = QtScriptDemo
TEMPLATE = app

SOURCES += \
    main.cpp

OTHER_FILES += \
    js/script.js

FORMS += \
    ui/form.ui

RESOURCES += \
    resource.qrc

HEADERS += \
    ../src/uildinvoker.h \
    ../src/seinvoker.h

SOURCES += \
    ../src/uildinvoker.cpp \
    ../src/seinvoker.cpp
