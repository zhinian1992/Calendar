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
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setAttribute(Qt::WA_StyledBackground,true);

    this->setGeometry(pos.rx(),pos.ry(),DETAILWNDWIDTH,DETAILWNDHEIGHT);

    this->setWindowOpacity(0.9);
}

DetailWnd::~DetailWnd()
{
    delete ui;
}
