#include "mainwindow.h"
#include <QApplication>

#include "_mx_qt_include.h"
#include "miniblinkwidget.h"


#include "gumbo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mxtoolkit::MiniBlinkWidget::wkeInit();

    GumboOutput* out = gumbo_parse("<h>ddd</h>");

    MainWindow w;
    w.show();

    int ret = a.exec();

    mxtoolkit::MiniBlinkWidget::wkeFinal();

    return ret;
}
