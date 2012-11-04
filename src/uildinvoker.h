#ifndef UILDINVOKER_H
#define UILDINVOKER_H



class QUiLoader;
class QWidget;
class QString;

class UiLdInvoker
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
