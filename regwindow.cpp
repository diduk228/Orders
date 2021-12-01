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

void RegWindow::get_data()
{
    QVector<QString> vec;
    vec.push_back(ui->login->text());
    vec.push_back(ui->password->text());
    vec.push_back(ui->phone->text());
    vec.push_back(ui->person_name->text());
    vec.push_back(ui->name_company->text());
    vec.push_back(ui->adress->text());
    reg_user(vec);
}

void RegWindow::on_regBtn_clicked()
{
    RegWindow::get_data();
}
