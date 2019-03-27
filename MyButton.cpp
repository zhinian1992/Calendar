#include "MyButton.h"
#include "ui_MyButton.h"

#include <QMouseEvent>

MyButton::MyButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyButton)
{
    ui->setupUi(this);
    //设置样式
    this->setAttribute(Qt::WA_StyledBackground,true);
}

MyButton::~MyButton()
{
    delete ui;
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

void MyButton::enterEvent(QEvent *event)
{

}

void MyButton::leaveEvent(QEvent *event)
{

}
