#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class MyLabel;
}

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();

signals:
    void clicked();

private:
    void enterEvent(QEvent *event)Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event)Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *ev)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *ev)Q_DECL_OVERRIDE;

private:
    Ui::MyLabel *ui;
};

#endif // MYLABEL_H
