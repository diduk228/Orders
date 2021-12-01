#ifndef DELETEPRODUCTS_H
#define DELETEPRODUCTS_H
#include "basedata.h"
#include "mainwindow.h"
#include <QMainWindow>

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
};

#endif // DELETEPRODUCTS_H
