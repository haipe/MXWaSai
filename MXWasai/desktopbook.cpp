#include "desktopbook.h"

DesktopBook::DesktopBook(QWidget *parent) : QWidget(parent)
{
    label_text = new QLabel(this);
    this->layout()->addWidget(label_text);

    font.setPointSize(30);
    font.setBold(true);

    label_text->setFont(font);
    label_text->setWordWrap(true);

    showText();
}

DesktopBook::~DesktopBook()
{

}

void DesktopBook::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        Position = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    else if (event->button() == Qt::RightButton)
    {
        close();
    }
}

void DesktopBook::mouseMoveEvent(QMouseEvent *event)
{
    move(event->globalPos() - Position);
    event->accept();
}

void DesktopBook::showText()
{
    color = QColor::fromHsl(rand() % 360, rand() % 256, rand() % 200);
    pe.setColor(QPalette::WindowText, color);
    label_text->setPalette(pe);
    QString sql = "SELECT sentence FROM muxin WHERE id = ";

    label_text->setText(sql);
}
