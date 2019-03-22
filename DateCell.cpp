#include "DateCell.h"
#include "ui_DateCell.h"

#include <QDate>

#define CURRENTDAYSTYLE "QWidget{background-color: rgb(204,255,204);}"
#define CURRENTMONTHSTYLE "QWidget{background-color: rgb(255,255,255);}"
#define OTHERMONTHDAYSTYLE "QWidget{background-color: rgb(242,242,242);}"


#define CELLWIDTH 100
#define CELLHEIGHT 60

DateCell::DateCell(int iNO,QWidget *parent) :
    QWidget(parent),
    m_CellNO(iNO),
    ui(new Ui::DateCell)
{
    ui->setupUi(this);

    int iLineNO = m_CellNO/7;
    int iColumnNO = m_CellNO%7;
    this->setGeometry(iColumnNO*CELLWIDTH,iLineNO*CELLHEIGHT + 110,CELLWIDTH,CELLHEIGHT);
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
    if(bCurrentDay)
        this->setStyleSheet(CURRENTDAYSTYLE);
    else
    {
        if(bCurrentMonth)
            this->setStyleSheet(CURRENTMONTHSTYLE);
        else
            this->setStyleSheet(OTHERMONTHDAYSTYLE);
    }
}
