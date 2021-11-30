#include "basedata.h"
BaseData::BaseData() : User(nullptr, nullptr, nullptr, 0, nullptr, nullptr, nullptr,0)
{

}

bool BaseData::init_user(QString login, QString password)
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
        return 0;
    }
    //Подключение к MySql

    //Запрос
    QSqlQuery *query = new QSqlQuery(db);
    query->exec(QString("SELECT mod, name, adress, phone, name_person FROM DB_users WHERE name = %1 AND password = %2").arg(login).arg(password)); // запрашиваем все поля для заданного пароля и логин

    if(!query->at())
    {
        QMessageBox::warning(this, "Ошибка", "Не правильный пароль или логин" );
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
    return 1;
}
