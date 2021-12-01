#include "addgoods.h"
#include "ui_addgoods.h"

AddGoods::AddGoods(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::AddGoods)
{
    ui->setupUi(this);
}

AddGoods::~AddGoods()
{
    delete ui;
}

void AddGoods::on_pushButton_2_clicked()
{
    MainWindow *m = new MainWindow(this);
    this->close();
    m->show();
}

void AddGoods::on_pushButton_clicked()
{
    QVector<QString> vec;
    vec.push_back(ui->name_goods->text());
    vec.push_back(ui->dilivery->text());
    vec.push_back(ui->cost->text());
    vec.push_back(ui->count_goods->text());
    vec.push_back(ui->link_to_documentation->text());
    vec.push_back(ui->path_to_jpg->text());
    if(!add_product(vec))
    {
        return;
    }
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Товар добавлен в базу.");
    msgBox.exec();

}
