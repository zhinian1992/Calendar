#include "DateCell.h"
#include "ui_DateCell.h"

DateCell::DateCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateCell)
{
    ui->setupUi(this);
}

DateCell::~DateCell()
{
    delete ui;
}
