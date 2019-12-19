﻿#include "mainwindow.h"
#include <QApplication>

#include "_qt_include.h"
#include "miniblinkwidget.h"

#include "desktopbook.h"

void MessageBoxA(HWND,const char* msg, const char* func, int)
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

    MiniBlinkWidget* mini = new MiniBlinkWidget(webFrame);
    webFrame->layout()->addWidget(mini);

    DesktopBook db;
    db.resize(600,400);
    db.setWindowOpacity(1.0);
    db.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    db.setAttribute(Qt::WA_TranslucentBackground);
    db.show();

    int ret = a.exec();

    MiniBlinkWidget::wkeFinal();

    return ret;
}