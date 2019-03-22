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
    explicit DateCell(QWidget *parent = 0);
    ~DateCell();

private:
    Ui::DateCell *ui;
};

#endif // DATECELL_H
