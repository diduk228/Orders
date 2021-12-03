#ifndef PROCESSORDERSWINDOW_H
#define PROCESSORDERSWINDOW_H
#include "basedata.h"
#include <QMainWindow>
#include "mainwindow.h"
#include <QObject>
namespace Ui {
class ProcessOrdersWindow;
}

class ProcessOrdersWindow : public BaseData
{
    Q_OBJECT

public:
    explicit ProcessOrdersWindow(QWidget *parent = nullptr);
    ~ProcessOrdersWindow();

private slots:
    void on_pushButton_2_clicked();  // КНопка возваращения в главное меню
    void on_pushButton_3_clicked();  // КНопка принять изменения

private:
    Ui::ProcessOrdersWindow *ui;
    void init_table();  //Заполняет таблицу
    void addCheckBoxAt(int row_number, int column_number, QString name);  //Добавляет чекбоксы в таблицу
};

#endif // PROCESSORDERSWINDOW_H
