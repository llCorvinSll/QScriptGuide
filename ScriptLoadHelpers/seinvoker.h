#ifndef SEINVOKER_H
#define SEINVOKER_H

#include<QScriptEngine>
#include<QFile>
#include<QDebug>
#include "ScriptLoadHelpers_global.h"

class SCRIPTLOADHELPERSSHARED_EXPORT SEInvoker
{
private:
    SEInvoker();
    SEInvoker(const SEInvoker&);
    SEInvoker &operator=(const SEInvoker&);
    //------
    static QScriptEngine *_engine;
public:
    ~SEInvoker();

    static void init(QScriptEngine *e);
    static const SEInvoker& i();
    static void wipeOf();
    static bool loadFromFile(QFile& scriptFile);
    static bool loadFromFile(QString fileName);
    static QScriptEngine &getSE();
};

#endif // SEINVOKER_H
