#ifndef AUTWINDW_H
#define AUTWINDW_H
#include "basedata.h"
#include <QMainWindow>
#include "regwindow.h"
#include "mainwindow.h"

namespace Ui {
class AutWindw;
}

class AutWindw : public BaseData
{
    Q_OBJECT

public:
    explicit AutWindw(QWidget *parent = nullptr);
    ~AutWindw();

private slots:

    void on_Btn_Enter_clicked(); // Вызывается метод из класса basedata, запрос на авторизацию
    void on_regtoBtn_clicked();  // Кнопка для перехода в меню регистрации

private:
    Ui::AutWindw *ui;


};

#endif // AUTWINDW_H
