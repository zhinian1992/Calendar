#include "CalendarWnd.h"
#include "ui_CalendarWnd.h"

#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>

CalendarWnd::CalendarWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarWnd)
{
    ui->setupUi(this);

   //设置无边框
   this->setWindowFlag(Qt::FramelessWindowHint);
   //设置透明
   this->setAttribute(Qt::WA_TranslucentBackground);
   //实例shadow
   QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
   //设置阴影距离
   shadow->setOffset(0,0);
   //设置阴影颜色
   shadow->setColor(Qt::gray);
   //设置阴影圆角
   shadow->setBlurRadius(12);
   //设置窗体阴影
   ui->widget->setGraphicsEffect(shadow);
}

CalendarWnd::~CalendarWnd()
{
    delete ui;
}

void CalendarWnd::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bMousePress = true;
        m_MousePressPos = event->globalPos();
    }
}

void CalendarWnd::mouseReleaseEvent(QMouseEvent *event)
{
    m_bMousePress = false;
}

void CalendarWnd::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bMousePress)
    {
        m_MouseMovePos = event->globalPos();
        this->move(this->pos() + m_MouseMovePos - m_MousePressPos);
        m_MousePressPos = m_MouseMovePos;
    }
}
