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

    ui->centralwidget->setStyleSheet("background-color: #494A5F;");

    QString path = "file:///" + QCoreApplication::applicationDirPath() + "/Web/index.html";

    statusBar()->showMessage(tr("Ready"));
    statusBar()->setStyleSheet("background-color: #494A5F;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoadFinished(bool ok)
{
    //m_webEngineView->setVisible(true);
    //m_webEngineView->reload();
}

