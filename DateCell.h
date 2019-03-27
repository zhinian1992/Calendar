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
    void enterEvent(QEvent *event)Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event)Q_DECL_OVERRIDE;

private:
    Ui::DateCell *ui;
    int m_CellNO;
    bool m_IsCurrentDay;
    bool m_IsCurrentMonth;
};

#endif // DATECELL_H
