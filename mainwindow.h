#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basedata.h"
#include "processorderswindow.h"
#include "deleteproducts.h"
#include "addgoods.h"
#include "menubasket.h"
#include "algorithm"
#include "QFile"
#include <QTextStream>
namespace Ui {
class MainWindow;
}

class MainWindow : public BaseData
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString m_current_product_id;   //Показывает какой товар смотрит пользователь
    QVector<QString> ids;           //Вектор товаров, которые пользователь добавил в корзину

private slots:
    void on_process_products_2_triggered(); // Открывает меню обработки заказов
    void on_delete_products_triggered();    // Открывает меню удаления товаров
    void on_add_goods_triggered();          // Открывает меню добавления товаров
    void on_go_to_basket_clicked();         // Открывает Корзину
    void on_add_to_basket_clicked();        // Добавляет товар в Корзину
    void onBtnClicked();                    // Узнаём какой товар сейчас смотрит заказчик
    void on_buy_product_clicked();          //конпка покупки товара
    void on_delete_from_basket_clicked();   //удаляет товар из корзины

private:
    void init_table();  // Иницилизирует таблицу в главном меню
    void addBtnAt(int row_number, int column_number);  //добавляет в таблицу кнопки
    void save_ids();                   // сохраняет переменную
    void set_ids();                    // Загружает переменную
    void save_current();                   // сохраняет переменную
    void set_current();                    // Загружает переменую
public:
    void set_m_current_product_id(QString current);  //сетер
    QString get_m_current_product_id();  //геттер
     QVector<QString> get_ids();                     //геттер
     QPushButton* get_ui_btn_add_to_basket();           //геттер

};

#endif // MAINWINDOW_H
