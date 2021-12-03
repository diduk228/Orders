#ifndef MENUBASKET_H
#define MENUBASKET_H

#include <QMainWindow>
#include "basedata.h"
#include "QHBoxLayout"
#include "mainwindow.h"
namespace Ui {
class MenuBasket;
}

class MenuBasket : public BaseData
{
    Q_OBJECT

public:
    explicit MenuBasket(QWidget *parent = nullptr);
    explicit MenuBasket(QVector<QString> ids, QWidget *parent = nullptr);
    ~MenuBasket();

private slots:
    void on_return_to_menu_clicked();

    void on_buy_goods_clicked();

private:
    Ui::MenuBasket *ui;

private:
    void init_table(QVector<QString> ids);                              // Иницилизирует таблицу в Корзине
    void addCheckBoxAt(int row_number, int column_number);              // Добавляет в таблицу чекбоксы
};

#endif // MENUBASKET_H
