#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webView = new mxtoolkit::MiniBlinkWidget(this,"www.wasai.life");
    ui->centralwidget->layout()->addWidget(webView);
    webView->hide();

    ui->centralwidget->setStyleSheet("background-color: #494A5F;");

    QString path = "file:///" + QCoreApplication::applicationDirPath() + "/Web/index.html";

    statusBar()->showMessage(tr("Loading..."));
    statusBar()->setStyleSheet("background-color: #494A5F;");

    connect(webView,SIGNAL(onLoadUrlCompleted()),this,SLOT(onLoadFinished()),Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoadFinished()
{
    webView->show();
    statusBar()->showMessage(tr("Ready"));
}

