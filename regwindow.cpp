#include "regwindow.h"
#include "ui_regwindow.h"
#include "autwindw.h"

RegWindow::RegWindow(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::RegWindow)
{
    ui->setupUi(this);
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::on_ComeBack_clicked()
{
    AutWindw *w = new AutWindw(this);
    this->close();
    w->show();
}
