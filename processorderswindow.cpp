#include "processorderswindow.h"
#include "ui_processorderswindow.h"

ProcessOrdersWindow::ProcessOrdersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProcessOrdersWindow)
{
    ui->setupUi(this);
}

ProcessOrdersWindow::~ProcessOrdersWindow()
{
    delete ui;
}
