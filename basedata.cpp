#include "basedata.h"
BaseData::BaseData(QWidget *parent) : User(nullptr, nullptr, nullptr, 0, nullptr, nullptr, nullptr,parent)
{
    //Подключение к MySql
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "mydb");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("basic_sql");
    db.setUserName("root");
    db.setPassword("admin");
    if(!db.open())
    {
        QMessageBox::warning(this, "Ошибка", "Нет доступа к базе данных" );
    }
    //Подключение к MySql
}
BaseData::~BaseData()
{
    db.close();
    QSqlDatabase::removeDatabase("mydb");
}

bool BaseData::init_user(QString login, QString password)
{
    //Запрос
    QSqlQuery *query = new QSqlQuery(db);
    query->exec(QString("SELECT mod, name, adress, phone, name_person FROM DB_users WHERE name = %1 AND password = %2").arg(login).arg(password)); // запрашиваем все поля для заданного пароля и логин

    if(!query->at())
    {
        QMessageBox::warning(this, "Ошибка", "Не правильный пароль или логин" );
        delete  query;
        return 0;
    }
    while (query->next()) {
      QString mod = query->value(0).toString();
      QString name = query->value(1).toString();
      QString adress = query->value(2).toString();
      int phone = query->value(3).toInt();
      QString name_person = query->value(4).toString();
      User::set(mod, name, adress, phone, name_person, login, password);
    }
    delete  query;
    return 1;
}

bool BaseData::reg_user(QVector<QString> data)
{
    QSqlQuery *query = new QSqlQuery(db);
    query->exec(QString("INSERT INTO DB_users (login, password, phone, name_person, name, adress) "
         "VALUES ('%1', '%2', %3, '%4', '%5', '%6").arg(data[0]).arg(data[1]).arg(data[2]).arg(data[3]).arg(data[4]).arg(data[5]));
    if(!query->exec())
    {
        QMessageBox::warning(this, "Ошибка", "Введены не корректные данные, или такой пользователь уже существует." );
        delete query;
        return 0;
    }
    delete query;
    return 1;
}
