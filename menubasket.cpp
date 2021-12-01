#include "menubasket.h"
#include "ui_menubasket.h"

MenuBasket::MenuBasket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuBasket)
{
    ui->setupUi(this);
}

MenuBasket::~MenuBasket()
{
    delete ui;
}
