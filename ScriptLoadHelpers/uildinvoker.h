#ifndef UILDINVOKER_H
#define UILDINVOKER_H

#include "ScriptLoadHelpers_global.h"

class QUiLoader;
class QWidget;

class SCRIPTLOADHELPERSSHARED_EXPORT UiLdInvoker
{
private:
    UiLdInvoker();
    UiLdInvoker(const UiLdInvoker&);
    UiLdInvoker &operator=(const UiLdInvoker&);

    static QUiLoader* _loader;
public:
    static void init();
    static void wipeOf();
    static const UiLdInvoker& i();

    static QWidget* LoadUi(QString fileName);

};

#endif // UILDINVOKER_H
