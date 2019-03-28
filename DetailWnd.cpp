#include "DetailWnd.h"
#include "ui_DetailWnd.h"

#define DETAILWNDWIDTH 200
#define DETAILWNDHEIGHT 300

DetailWnd::DetailWnd(QPoint pos,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailWnd)
{
    ui->setupUi(this);

    //设置无边框
    this->setWindowFlag(Qt::FramelessWindowHint);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setGeometry(pos.rx(),pos.ry(),200,200);

    this->setWindowOpacity(0.7);
}

DetailWnd::~DetailWnd()
{
    delete ui;
}
