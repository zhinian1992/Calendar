#include "DateCell.h"
#include "ui_DateCell.h"

#include <QDate>

#define CURRENTDAYSTYLE "QLabel{background-color: rgb(102,205,170);}"
#define CURRENTMONTHSTYLE "QLabel{background-color: rgb(255,255,255);}"
#define OTHERMONTHDAYSTYLE "QLabel{background-color: rgb(238,238,209);}"
#define MOUSEENTERSTYLE "QLabel{background-color: rgb(191,239,255);}"

#define CELLWIDTH 100
#define CELLHEIGHT 60

DateCell::DateCell(int iNO,QWidget *parent) :
    QWidget(parent),
    m_CellNO(iNO),
    m_IsCurrentDay(false),
    m_IsCurrentMonth(false),
    ui(new Ui::DateCell)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground,true);

    int iLineNO = m_CellNO/7;
    int iColumnNO = m_CellNO%7;
    this->setGeometry(iColumnNO*CELLWIDTH,iLineNO*CELLHEIGHT + 100,CELLWIDTH,CELLHEIGHT);
}

DateCell::~DateCell()
{
    delete ui;
}

void DateCell::setCellText(QDate qDate, QString qsTask)
{
    QString qsDay = qDate.toString("dd");
    ui->dateLabel->setText(qsDay);
    ui->taskLabel->setText(qsTask);
}

void DateCell::setCellStyle(bool bCurrentDay, bool bCurrentMonth)
{
    m_IsCurrentDay = bCurrentDay;
    m_IsCurrentMonth = bCurrentMonth;

    if(m_IsCurrentDay)
    {
        ui->dateLabel->setStyleSheet(CURRENTDAYSTYLE);
        ui->taskLabel->setStyleSheet(CURRENTDAYSTYLE);
    }
    else
    {
        if(m_IsCurrentMonth)
        {
            ui->dateLabel->setStyleSheet(CURRENTMONTHSTYLE);
            ui->taskLabel->setStyleSheet(CURRENTMONTHSTYLE);
        }
        else
        {
            ui->dateLabel->setStyleSheet(OTHERMONTHDAYSTYLE);
            ui->taskLabel->setStyleSheet(OTHERMONTHDAYSTYLE);
        }
    }
}

void DateCell::enterEvent(QEvent *event)
{
    if(!m_IsCurrentDay && m_IsCurrentMonth)
    {
        ui->dateLabel->setStyleSheet(MOUSEENTERSTYLE);
        ui->taskLabel->setStyleSheet(MOUSEENTERSTYLE);
    }
}

void DateCell::leaveEvent(QEvent *event)
{
    if(!m_IsCurrentDay && m_IsCurrentMonth)
    {
        ui->dateLabel->setStyleSheet(CURRENTMONTHSTYLE);
        ui->taskLabel->setStyleSheet(CURRENTMONTHSTYLE);
    }
}
