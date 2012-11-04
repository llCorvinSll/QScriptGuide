#include "uildinvoker.h"
#include <QtUiTools>

QUiLoader *UiLdInvoker::_loader = NULL;

UiLdInvoker::UiLdInvoker()
{
}

UiLdInvoker::UiLdInvoker(const UiLdInvoker &)
{
}


void UiLdInvoker::init()
{
    if(_loader == NULL)
        _loader = new QUiLoader();
}

void UiLdInvoker::wipeOf()
{
    if(_loader != NULL)
        delete _loader;
}

const UiLdInvoker& UiLdInvoker::i()
{
    static UiLdInvoker instance;
    return instance;
}

QWidget *UiLdInvoker::LoadUi(QString fileName)
{
    //открываем файл для того, чтобы передать в Движок
    QFile UiFile(fileName);
    if(UiFile.open(QIODevice::ReadOnly))
    {
        QWidget *ui = _loader->load(&UiFile);
        UiFile.close();
        return ui;
    }
    return NULL;
}
