#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>
#include "basedata.h"
namespace Ui {
class RegWindow;
}

class RegWindow : public BaseData
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();

private slots:
    void on_ComeBack_clicked(); // открывает окно авторизации

private:
    Ui::RegWindow *ui;

};

#endif // REGWINDOW_H
