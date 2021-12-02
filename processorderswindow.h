#ifndef PROCESSORDERSWINDOW_H
#define PROCESSORDERSWINDOW_H
#include "basedata.h"
#include <QMainWindow>

namespace Ui {
class ProcessOrdersWindow;
}

class ProcessOrdersWindow : public BaseData
{
    Q_OBJECT

public:
    explicit ProcessOrdersWindow(QWidget *parent = nullptr);
    ~ProcessOrdersWindow();

private:
    Ui::ProcessOrdersWindow *ui;
    void init_table();  //Заполняет таблицу
    void addCheckBoxAt(int row_number, int column_number, int state, QString name);  //Добавляет чекбоксы в таблицу
};

#endif // PROCESSORDERSWINDOW_H
