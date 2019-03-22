#include "CalendarWnd.h"
#include "ui_CalendarWnd.h"
#include "DateCell.h"

#include <vector>

#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QDate>

std::vector<DateCell *> m_CellList;

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

   for(int i = 0; i< 42;i++)
   {
       DateCell *cell = new DateCell(i,ui->widget);
       m_CellList.push_back(cell);
   }

   this->updateCellText();
}

CalendarWnd::~CalendarWnd()
{
    delete ui;
}

void CalendarWnd::updateCellText()
{
    QDate date = QDate::currentDate();
    int iDayInWeek = date.dayOfWeek();
    int iDayInMonth = date.day();
    date = date.addDays(1 - iDayInMonth);
    int iDayInWeek_firstDayInMonth = date.dayOfWeek();
    QDate first_cell_date = date.addDays(- iDayInWeek_firstDayInMonth);

    for(int i = 0;i<m_CellList.size();i++)
    {
        m_CellList.at(i)->setCellText(first_cell_date);

        if(i<iDayInWeek_firstDayInMonth ||
                i >= date.daysInMonth() + iDayInWeek_firstDayInMonth)
        {
            m_CellList.at(i)->setCellStyle(false,false);
        }
        else if( i == iDayInWeek_firstDayInMonth + iDayInMonth - 1)
        {
            m_CellList.at(i)->setCellStyle(true,true);
        }
        else
            m_CellList.at(i)->setCellStyle(false,true);

        first_cell_date = first_cell_date.addDays(1);
    }
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
