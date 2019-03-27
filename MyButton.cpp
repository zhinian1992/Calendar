#include "MyButton.h"
#include "ui_MyButton.h"

MyButton::MyButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyButton)
{
    ui->setupUi(this);
}

MyButton::~MyButton()
{
    delete ui;
}
