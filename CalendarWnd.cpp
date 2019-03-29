#include "CalendarWnd.h"
#include "ui_CalendarWnd.h"
#include "DateCell.h"
#include "MyButton.h"

#include <vector>
#include <Windows.h>



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
   //创建托盘图标
   this->bindSystemTray();
   //创建日历格子
   for(int i = 0; i< 42;i++)
   {
       DateCell *cell = new DateCell(i,ui->widget);
       m_CellList.push_back(cell);
   }
   //创建日期变换按钮行

   m_CurrentDate = QDate::currentDate();
   this->updateCellText();

   connect(ui->btn_Close,&MyButton::clicked,this,&CalendarWnd::hide);
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

void CalendarWnd::bindSystemTray()
{
    m_Tray = new QSystemTrayIcon();
    m_Tray->setIcon(QIcon("resource/tray.ico"));
    m_Tray->setToolTip(QStringLiteral("Calendar"));
    connect(m_Tray,&QSystemTrayIcon::activated,this,&CalendarWnd::systemTrayClicked);

    m_TrayMenu = new QMenu();
    QAction *pClose = new QAction(QStringLiteral("close"),m_TrayMenu);
    m_TrayMenu->addAction(pClose);
    connect(pClose,&QAction::triggered,this,&CalendarWnd::close);

    m_Tray->setContextMenu(m_TrayMenu);
    m_Tray->show();
}

void CalendarWnd::systemTrayClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        this->show();
        break;
    default:
        break;
    }
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

void CalendarWnd::closeEvent(QCloseEvent *event)
{
    m_Tray->hide();
    event->accept();
}

bool CalendarWnd::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = (MSG*)message;
    switch (msg->message) {
    default:
        break;
    }
    return QWidget::nativeEvent(eventType,message,result);
}
