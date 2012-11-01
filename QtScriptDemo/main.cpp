#include <QApplication>

#include "src/invoker.h"
#include <QWidget>
#include <QtScript>
#include <QtUiTools>


#include <QMainWindow>
#ifndef QT_NO_SCRIPTTOOLS
#include <QScriptEngineDebugger>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Q_INIT_RESOURCE(resource);

/*
 *если есть возможность для отладки (QSCRIPTTOOLS)
 *создаем дебаггер для отладки, прикрепляем его к нашему движку
 *и создаем стандартное окно, которое ммы увидим если в скрипте будет ошибка
*/
#if !defined(QT_NO_SCRIPTTOOLS)
    QScriptEngineDebugger debugger;
    debugger.attachTo(&Invoker::i().getEngine());
    QMainWindow *debugWindow = debugger.standardWindow();
    debugWindow->resize(1024, 640);
#endif

    QString s;    
    s = ":/js/script.js";
    Invoker::i().invoke(s);
    s = ":/ui/form.ui";
    QWidget *ui = Invoker::i().loadUi(s);
    QScriptValue ctor = Invoker::i().getEngine().evaluate("ExampleThisUi");
    QScriptValue scriptUi =
            Invoker::i().getEngine().newQObject(ui, QScriptEngine::ScriptOwnership);
    QScriptValue tut = ctor.construct(QScriptValueList() << scriptUi);

    ui->show();

    return a.exec();
}
