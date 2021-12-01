#include "basedata.h"
BaseData::BaseData(QWidget *parent) : User(nullptr, nullptr, nullptr, 0, nullptr, nullptr, nullptr,parent)
{
}
BaseData::~BaseData()
{
    //db.close();
    //QSqlDatabase::removec("mydb");
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
    }
    //Подключение к MySql

    //Запрос
    QSqlQuery *query = new QSqlQuery(db);
    query->exec(QString("SELECT mod_person, name_person, adress, phone, name_company FROM users WHERE login = '%1' AND password = '%2'").arg(login).arg(password)); // запрашиваем все поля для заданного пароля и логин

    if(!query->next())
    {
        delete  query;
        QMessageBox::warning(this, "Ошибка", "Не правильный пароль или логин" );
        return 0;
    }
    else
    {
        QString mod = query->value(0).toString();
        QString name = query->value(1).toString();
        QString adress = query->value(2).toString();
        int phone = query->value(3).toString().toInt();
        QString name_person = query->value(4).toString();
        User::set(mod, name, adress, phone, name_person, login, password);
        delete  query;
        return 1;
    }

    delete  query;
    return 1;
}

bool BaseData::reg_user(QVector<QString> data)
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

    QSqlQuery *query = new QSqlQuery(db);
    QString str = QString("INSERT INTO users (login, password, phone, name_person, name_company, adress) VALUES ('%1', '%2', '%3', '%4', '%5', '%6')").arg(data[0]).arg(data[1]).arg(data[2]).arg(data[3]).arg(data[4]).arg(data[5]);
    if(!query->exec(str))
    {
        delete query;
        QMessageBox::warning(this, "Ошибка", "Введены не корректные данные, или такой пользователь уже существует." );
        return 0;
    }
    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return 1;
}

bool BaseData::add_product(QVector<QString> data)
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

    QSqlQuery *query = new QSqlQuery(db);
    QString str = QString("INSERT INTO goods (name_goods, dilivery, cost, count_goods, links_to_documetation, path_to_jpg) VALUES ('%1', '%2', %3, %4, '%5', '%6')").arg(data[0]).arg(data[1]).arg(data[2]).arg(data[3]).arg(data[4]).arg(data[5]);
    if(!query->exec(str))
    {
        delete query;
        QMessageBox::warning(this, "Ошибка", "Введены не корректные данные." );
        return 0;
    }
    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return 1;
}
