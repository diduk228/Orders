#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_process_products_2_triggered()
{
    ProcessOrdersWindow *pro = new ProcessOrdersWindow(this);
    this->close();
    pro->show();
}

void MainWindow::on_delete_products_triggered()
{
    DeleteProducts *del = new DeleteProducts(this);
    this->close();
    del->show();
}
