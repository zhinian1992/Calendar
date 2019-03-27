#ifndef CALENDARWND_H
#define CALENDARWND_H

#include <QWidget>
#include <QDate>

namespace Ui {
class CalendarWnd;
}

class CalendarWnd : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWnd(QWidget *parent = 0);
    ~CalendarWnd();

private:
    void updateCellText();
    void goToNextMonth();
    void goToNextYear();
    void goToLastMonth();
    void goToLastYear();
    void backToToday();

private:
    Ui::CalendarWnd *ui;

    QDate m_CurrentDate;


};

#endif // CALENDARWND_H
