#include "deleteproducts.h"
#include "ui_deleteproducts.h"

DeleteProducts::DeleteProducts(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::DeleteProducts)
{
    ui->setupUi(this);
    init_table();
}

DeleteProducts::~DeleteProducts()
{
    delete ui;
}

void DeleteProducts::init_table()
{
    QVector<QVector<QString>> vec =  get_all();
    for(int i = 0; i < get_count_products(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(vec[i][j]));
            ui->tableWidget->setItem(i,j, itm);
        }

    }
}
