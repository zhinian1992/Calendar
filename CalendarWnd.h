#ifndef CALENDARWND_H
#define CALENDARWND_H

#include <QWidget>
#include <QDate>
#include <QSystemTrayIcon>
#include <QGraphicsDropShadowEffect>
#include <QAction>
#include <QMenu>

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
    void bindSystemTray();
    void systemTrayClicked(QSystemTrayIcon::ActivationReason reason);
    void updateCellText();
    void goToNextMonth();
    void goToNextYear();
    void goToLastMonth();
    void goToLastYear();
    void backToToday();

    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;
    bool nativeEvent(const QByteArray &eventType, void *message, long *result)Q_DECL_OVERRIDE;
private:
    Ui::CalendarWnd *ui;
    QSystemTrayIcon *m_Tray;
    QMenu *m_TrayMenu;
    QDate m_CurrentDate;


};

#endif // CALENDARWND_H
