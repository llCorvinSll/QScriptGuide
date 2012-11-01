#include "invoker.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QScriptEngine>
#include <QtUiTools>
#include <QDebug>

QScriptEngine *Invoker::_engine = NULL;
QUiLoader *Invoker::_uiLoader = NULL;

Invoker::Invoker(QObject *parent) :
    QObject(parent)
{
    if(_engine == NULL)
    {
        _engine = new QScriptEngine();
    }
    if(_uiLoader == NULL)
        _uiLoader = new QUiLoader();
}

void Invoker::invoke(QString fileName)
{
    //открываем файл для того, чтобы передать в Движок
    QFile scriptFile(fileName);
    if(scriptFile.open(QIODevice::ReadOnly))
    {
        QScriptValue v = _engine->evaluate(scriptFile.readAll(),fileName);
        scriptFile.close();
    }
    else
    {
        QMessageBox::warning(0, tr("js read error!!!"),
                             "can't open file\n" + fileName +
                             "\nWhere is it?");
    }
}

QScriptEngine &Invoker::getEngine()
{
    return *_engine;
}

QWidget *Invoker::loadUi(QString fileName)
{
    //открываем файл для того, чтобы передать в Движок
    QFile UiFile(fileName);
    if(UiFile.open(QIODevice::ReadOnly))
    {
        QWidget *ui = _uiLoader->load(&UiFile);
        UiFile.close();
        return ui;
    }
    else
    {
        QMessageBox::warning(0, tr("ui file read error!!!"),
                             "can't open file\n" + fileName +
                             "\nWhere is it?");
    }
    return NULL;

}


void Invoker::wipeOf()
{
    if(_engine != NULL)
        delete _engine;
    if(_uiLoader != NULL)
        delete _uiLoader;
}


const Invoker &Invoker::i()
{
    static Invoker instance;
    return instance;
}


Invoker::~Invoker()
{
    qDebug() << "atatatata";
    wipeOf();
}
