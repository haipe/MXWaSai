#ifndef DESKTOPBOOK_H
#define DESKTOPBOOK_H


#include "_qt_include.h"


class DesktopBook : public QWidget
{
    Q_OBJECT
public:
    explicit DesktopBook(QWidget *parent = nullptr);
    virtual ~DesktopBook() override;

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
private slots:
    void showText();

private:
    QLabel* label_text;

    QPoint Position;

    QPalette pe;
    QFont font;
    QColor color;

};

#endif // DESKTOPBOOK_H
