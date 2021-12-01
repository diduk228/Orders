#ifndef DELETEPRODUCTS_H
#define DELETEPRODUCTS_H
#include "basedata.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QCheckBox>

namespace Ui {
class DeleteProducts;
}

class DeleteProducts : public BaseData
{
    Q_OBJECT

public:
    explicit DeleteProducts(QWidget *parent = nullptr);
    ~DeleteProducts();

private:
    Ui::DeleteProducts *ui;

public:
    void init_table();
private slots:
    void on_pushButton_clicked();
    void addCheckBoxAt(int row_number, int column_number,int state);
};

#endif // DELETEPRODUCTS_H
