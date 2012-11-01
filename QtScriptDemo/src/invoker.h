#ifndef INVOKER_H
#define INVOKER_H
#include <QObject>

class QScriptEngine;
class QUiLoader;

/*
 *класс, который одержит в себе скриптовый движок и загрузчик форм
 *перый служит как исполняемое окружение для наших скриптов
 *второй -
*/
class Invoker : public QObject
{
    Q_OBJECT
private:
    Invoker(QObject *parent = 0);
    Invoker(const Invoker&);
    Invoker &operator=(const Invoker&);
    //------
    static QScriptEngine *_engine;
    static QUiLoader *_uiLoader;
public:
    ~Invoker();

    static const Invoker& i();
    static void wipeOf();
    static void invoke(QString fileName);
    static QScriptEngine &getEngine();

    static QWidget *loadUi(QString fileName);
signals:

public slots:
};

#endif // INVOKER_H
