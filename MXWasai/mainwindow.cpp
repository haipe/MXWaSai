﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(QStringLiteral("mx哇塞"));

#ifdef QT_NO_DEBUG
    //QString path = "file:///" + QCoreApplication::applicationDirPath() + "/docs/index.html";
    QString path = "www.wasai.life";
#else
    QString path = "file:///" + QCoreApplication::applicationDirPath() + "/../../docs/index.html";
#endif

    webView = new mxtoolkit::MiniBlinkWidget(this,path.toStdString().c_str());//""
    ui->centralwidget->layout()->addWidget(webView);
    webView->hide();

    ui->centralwidget->setStyleSheet("background-color: #494A5F;");

    statusBar()->showMessage(tr("Loading..."));
    statusBar()->setStyleSheet("background-color: #494A5F;");

    connect(webView,SIGNAL(onLoadUrlCompleted()),this,SLOT(on_load_url_finished()));
    connect(webView,
            SIGNAL(onCreateWebView(wkeNavigationType, const QString&, const wkeWindowFeatures *)),
            this,
            SLOT(on_create_web_view(wkeNavigationType, const QString&, const wkeWindowFeatures *)));

    connect(webView,SIGNAL(onHookJSFunction(const QString&, const QString&)),this,SLOT(on_js_function(const QString&, const QString&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_url_finished()
{
    webView->show();
    webView->runJavaScript("initMXFrame()");

    webView->addHookJSFunction("onOpenApp");

    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::on_js_function(const QString &jsFunction, const QString &param)
{
    if(jsFunction == "onOpenApp")
    {
        qDebug() << "dasdasdsads" << param;
    }
}

mxtoolkit::MiniBlinkWidget* MainWindow::on_create_web_view(
        wkeNavigationType navType, const QString &url, const wkeWindowFeatures *features)
{
    return new mxtoolkit::MiniBlinkWidget(nullptr,url);
}

