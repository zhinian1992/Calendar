#ifndef DETAILWND_H
#define DETAILWND_H

#include <QWidget>

namespace Ui {
class DetailWnd;
}

class DetailWnd : public QWidget
{
    Q_OBJECT

public:
    explicit DetailWnd(QPoint pos,QWidget *parent = 0);
    ~DetailWnd();

private:
    Ui::DetailWnd *ui;
};

#endif // DETAILWND_H
