#ifndef CALENDARWND_H
#define CALENDARWND_H

#include <QWidget>

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
    Ui::CalendarWnd *ui;

    QPoint m_MousePressPos; //鼠标按下位置
    QPoint m_MouseMovePos;  //鼠标移动位置
    bool m_bMousePress;     //鼠标是否按下
protected:
    void updateCellText();
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // CALENDARWND_H
