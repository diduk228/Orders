#include "deleteproducts.h"
#include "ui_deleteproducts.h"

DeleteProducts::DeleteProducts(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::DeleteProducts)
{
    ui->setupUi(this);
}

DeleteProducts::~DeleteProducts()
{
    delete ui;
}
