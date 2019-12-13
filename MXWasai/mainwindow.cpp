#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //m_webEngineView = new QWebEngineView(this);
    //ui->centralwidget->layout()->addWidget(m_webEngineView);

    //m_webEngineView->load(QUrl("https://www.baidu.com"));
    ui->centralwidget->setStyleSheet("background-color: #494A5F;");

    QString path = "file:///" + QCoreApplication::applicationDirPath() + "/Web/index.html";

    //m_webEngineView->setVisible(false);
    //m_webEngineView->load(QUrl(path));
    //m_webEngineView->setContextMenuPolicy(Qt::NoContextMenu);

    statusBar()->showMessage(tr("Ready"));
    statusBar()->setStyleSheet("background-color: #494A5F;");
    //m_webEngineView->page()->runJavaScript()

    //QObject::connect(m_webEngineView,&QWebEngineView::loadStarted,[this](bool ok = true){this->onLoadFinished(ok);});
}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget *MainWindow::getWebFrame()
{
    return ui->centralwidget;
}

void MainWindow::onLoadFinished(bool ok)
{
    //m_webEngineView->setVisible(true);
    //m_webEngineView->reload();
}

