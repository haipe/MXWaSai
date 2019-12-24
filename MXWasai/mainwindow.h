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
    void onLoadFinished();

protected:
    mxtoolkit::MiniBlinkWidget* webView = nullptr;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
