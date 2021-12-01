#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basedata.h"
#include "processorderswindow.h"
#include "deleteproducts.h"
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

private slots:
    void on_process_products_2_triggered(); // открывает меню обработки заказов
    void on_delete_products_triggered();
};

#endif // MAINWINDOW_H
