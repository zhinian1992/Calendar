#include "MyLabel.h"
#include "ui_MyLabel.h"

#include <QEvent>

#define MOUSEHOVERSTYLE "QLabel{background-color: rgb(230,253,255);color: rgb(85, 170, 255);}"
#define MOUSECLICKSTYLE "QLabel{background-color: rgb(102,205,170);color: rgb(85, 170, 255);}"
#define MOUSELEAVETYLE "QLabel{background-color: rgb(255,255,255);color: rgb(85, 170, 255);}"

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::MyLabel)
{
    ui->setupUi(this);
}

MyLabel::~MyLabel()
{
    delete ui;
}

void MyLabel::enterEvent(QEvent *event)
{
    this->setStyleSheet(MOUSEHOVERSTYLE);
}

void MyLabel::leaveEvent(QEvent *event)
{
    this->setStyleSheet(MOUSELEAVETYLE);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        this->setStyleSheet(MOUSECLICKSTYLE);
        emit clicked();
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    this->setStyleSheet(MOUSEHOVERSTYLE);
}
