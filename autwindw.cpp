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
   if(!init_user(ui->login_line->text(), ui->password_line->text()))  // Вызывается метод из класса basedata, запрос на авторизацию
   {
       return;
   }

   QMessageBox msgBox(this);
   msgBox.setWindowTitle("Успешно");
   msgBox.setText("Вы успешно авторизовались!");
   msgBox.exec();
   MainWindow *w = new MainWindow(this);
   this->close();
   w->show();
}

void AutWindw::on_regtoBtn_clicked()
{
    RegWindow *regwindow = new RegWindow(this);
    this->close();
    regwindow->show();
}
