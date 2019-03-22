#include "DateCell.h"
#include "ui_DateCell.h"

#include <QDate>

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
