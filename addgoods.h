#ifndef ADDGOODS_H
#define ADDGOODS_H
#include "basedata.h"
#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class AddGoods;
}

class AddGoods : public BaseData
{
    Q_OBJECT

public:
    explicit AddGoods(QWidget *parent = nullptr);
    ~AddGoods();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddGoods *ui;
};

#endif // ADDGOODS_H
