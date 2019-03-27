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
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::CalendarWnd *ui;

    QPoint m_MousePressPos; //鼠标按下位置
    QPoint m_MouseMovePos;  //鼠标移动位置
    bool m_bMousePress;     //鼠标是否按下
    QDate m_CurrentDate;


};

#endif // CALENDARWND_H
