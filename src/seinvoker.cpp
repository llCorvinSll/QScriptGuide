#include "seinvoker.h"


QScriptEngine *SEInvoker::_engine = NULL;

SEInvoker::SEInvoker()
{
}


SEInvoker::~SEInvoker()
{
    this->wipeOf();
}

void SEInvoker::init(QScriptEngine *e)
{
    _engine = e;
}

const SEInvoker &SEInvoker::i()
{
    static SEInvoker insance;
    return insance;
}


void SEInvoker::wipeOf()
{
    if(_engine != NULL)
        delete _engine;
}

bool SEInvoker::loadFromFile(QString fileName)
{
    bool result = true;
    /*открываем файл для того, чтобы передать в Движок
     *не знаю, баг ли это, но если положить эту функцию в библиотеку,
     *то она не может открыть файл из ресурсов
     */
    QFile scriptFile(fileName);
    if(scriptFile.open(QIODevice::ReadOnly))
    {
        /*
         *если файл открылся, загружаем его в Движок и выполняем
         *после этого закрываем файл
         */
        QScriptValue v = _engine->evaluate(scriptFile.readAll(),scriptFile.fileName());
        scriptFile.close();
        /*
         *проверяем ,не вернули ли нам класс ошибки
         *и нет ли необработанных исключений
         */
        if(v.isError() || _engine->hasUncaughtException())
        {
            qDebug() << "Error in script evaluating";
            result = false;
        }
    }
    else
    {
        qDebug() << "Error loading file";
        result = false;
    }

    return result;
}


QScriptEngine &SEInvoker::getSE()
{
    return *_engine;
}
