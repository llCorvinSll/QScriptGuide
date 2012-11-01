#ifndef SEINVOKER_H
#define SEINVOKER_H

#include <QObject>

class QScriptEngine;

#include "ScriptLoadHelpers_global.h"

class SCRIPTLOADHELPERSSHARED_EXPORT SEInvoker:QObject
{
    Q_OBJECT
private:
    SEInvoker(QObject *parent = 0);
    SEInvoker(const SEInvoker&);
    SEInvoker &operator=(const SEInvoker&);
    //------
    static QScriptEngine *_engine;
public:
    ~SEInvoker();

    static void init();
    static const SEInvoker& i();
    static void wipeOf();
    static bool loadFromFile(QString fileName);
    static QScriptEngine &getSE();
};

#endif // SEINVOKER_H
