#include "MyButton.h"
#include "ui_MyButton.h"

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
