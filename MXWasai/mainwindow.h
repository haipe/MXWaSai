#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "miniblinkwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected Q_SLOTS:
    void on_load_url_finished();
    void on_js_function(const QString& jsFunction, const QString& param);

    mxtoolkit::MiniBlinkWidget* on_create_web_view(wkeNavigationType navType, const QString& url, const wkeWindowFeatures* features);

protected:
    mxtoolkit::MiniBlinkWidget* webView = nullptr;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
