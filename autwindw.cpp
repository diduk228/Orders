#include "autwindw.h"
#include "ui_autwindw.h"

AutWindw::AutWindw(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::AutWindw)
{
    ui->setupUi(this);
}

AutWindw::~AutWindw()
{
    delete ui;
}


void AutWindw::on_Btn_Enter_clicked()
{
   if(!init_user(ui->login_line->text(), ui->login_line->text()))  // Вызывается метод из класса basedata, запрос на авторизацию
   {
       return;
   }

   //тут будет открывать MainWidnow
}
