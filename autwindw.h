#ifndef AUTWINDW_H
#define AUTWINDW_H
#include "basedata.h"
#include <QMainWindow>

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


private:
    Ui::AutWindw *ui;


};

#endif // AUTWINDW_H
