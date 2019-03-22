#ifndef DATECELL_H
#define DATECELL_H

#include <QWidget>

namespace Ui {
class DateCell;
}

class DateCell : public QWidget
{
    Q_OBJECT

public:
    explicit DateCell(int iNO,QWidget *parent = 0);
    ~DateCell();
    void setCellText(QDate qDate,QString qsTask = "");
    void setCellStyle(bool bCurrentDay,bool bCurrentMonth);
private:
    Ui::DateCell *ui;
    int m_CellNO;
};

#endif // DATECELL_H
