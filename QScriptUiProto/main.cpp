#include <QApplication>

#include <QWidget>
#include <QtScript>
#include <QtUiTools>
#include "../src/seinvoker.h"
#include "../src/uildinvoker.h"
#include <QMainWindow>
#ifndef QT_NO_SCRIPTTOOLS
#include <QScriptEngineDebugger>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "a is done ";

    Q_INIT_RESOURCE(resource);

    SEInvoker::i().init(new QScriptEngine());
    UiLdInvoker::i().init();
/*
 *если есть возможность для отладки (QSCRIPTTOOLS)
 *создаем дебаггер для отладки, прикрепляем его к нашему движку
 *и создаем стандартное окно, которое ммы увидим если в скрипте будет ошибка
*/
#if !defined(QT_NO_SCRIPTTOOLS)
    QScriptEngineDebugger debugger;
    debugger.attachTo(&SEInvoker::i().getSE());
    QMainWindow *debugWindow = debugger.standardWindow();
    debugWindow->resize(1024, 640);
#endif

    SEInvoker::i().loadFromFile(":/js/script.js");

    QWidget *ui = UiLdInvoker::i().LoadUi(":/ui/form.ui");
    QScriptValue ctor = SEInvoker::i().getSE().evaluate("ExampleThisUi");
    QScriptValue scriptUi =
            SEInvoker::i().getSE().newQObject(ui, QScriptEngine::ScriptOwnership);
    QScriptValue tut = ctor.construct(QScriptValueList() << scriptUi);

    ui->show();

    return a.exec();
}
