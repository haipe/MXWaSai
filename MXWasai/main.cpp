#include "mainwindow.h"
#include <QApplication>

#include "roothead.h"
#include "MiniBlinkWidget.h"


void MessageBoxA(HWND w,const char* msg, const char* func, int)
{
    qDebug() << "[msg] " << msg << " [ " << func << " ]." ;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MiniBlinkWidget::wkeInit();

    MainWindow w;
    w.show();

    QWidget* webFrame = w.getWebFrame();

    MiniBlinkWidget* mini = new MiniBlinkWidget;
    webFrame->layout()->addWidget(mini);

    int ret = a.exec();

    MiniBlinkWidget::wkeFinal();

    return ret;
}
