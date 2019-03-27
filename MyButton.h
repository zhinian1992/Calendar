#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

namespace Ui {
class MyButton;
}

class MyButton : public QWidget
{
    Q_OBJECT

public:
    explicit MyButton(QWidget *parent = 0);
    ~MyButton();

signals:
    void clicked();

private:
    Ui::MyButton *ui;
    void mousePressEvent(QMouseEvent *event)Q_DECL_OVERRIDE;
    void enterEvent(QEvent *event)Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event)Q_DECL_OVERRIDE;
};

#endif // MYBUTTON_H
