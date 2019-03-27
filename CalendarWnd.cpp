#include "CalendarWnd.h"
#include "ui_CalendarWnd.h"
#include "DateCell.h"
#include "MyButton.h"

#include <vector>

#include <QGraphicsDropShadowEffect>


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
   //创建日历格子
   for(int i = 0; i< 42;i++)
   {
       DateCell *cell = new DateCell(i,ui->widget);
       m_CellList.push_back(cell);
   }
   //创建日期变换按钮行

   m_CurrentDate = QDate::currentDate();
   this->updateCellText();

   connect(ui->btn_Close,&MyButton::clicked,this,&QWidget::close);
   connect(ui->label_NextMonth,&MyLabel::clicked,this,&CalendarWnd::goToNextMonth);
   connect(ui->label_NextYear,&MyLabel::clicked,this,&CalendarWnd::goToNextYear);
   connect(ui->label_LastMonth,&MyLabel::clicked,this,&CalendarWnd::goToLastMonth);
   connect(ui->label_LastYear,&MyLabel::clicked,this,&CalendarWnd::goToLastYear);
   connect(ui->label_Return,&MyLabel::clicked,this,&CalendarWnd::backToToday);
}

CalendarWnd::~CalendarWnd()
{
    delete ui;
}

void CalendarWnd::updateCellText()
{
    QDate date = m_CurrentDate;
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
    ui->lineEdit_Date->setText(m_CurrentDate.toString("yyyy-MM-dd"));
}

void CalendarWnd::goToNextMonth()
{
    m_CurrentDate = m_CurrentDate.addMonths(1);
    m_CurrentDate = m_CurrentDate.addDays(-m_CurrentDate.day() + 1);
    updateCellText();
}

void CalendarWnd::goToNextYear()
{
    m_CurrentDate = m_CurrentDate.addYears(1);
    m_CurrentDate = m_CurrentDate.addDays(-m_CurrentDate.day() + 1);
    updateCellText();
}

void CalendarWnd::goToLastMonth()
{
    m_CurrentDate = m_CurrentDate.addMonths(-1);
    m_CurrentDate = m_CurrentDate.addDays(-m_CurrentDate.day() + 1);
    updateCellText();
}

void CalendarWnd::goToLastYear()
{
    m_CurrentDate = m_CurrentDate.addYears(-1);
    m_CurrentDate = m_CurrentDate.addDays(-m_CurrentDate.day() + 1);
    updateCellText();
}

void CalendarWnd::backToToday()
{
    m_CurrentDate = QDate::currentDate();
    updateCellText();
}
