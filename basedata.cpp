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
        db.close();
        QSqlDatabase::removeDatabase("mydb");
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
        db.close();
        QSqlDatabase::removeDatabase("mydb");
        delete  query;
        return 1;
    }

    db.close();
    QSqlDatabase::removeDatabase("mydb");
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
        db.close();
        QSqlDatabase::removeDatabase("mydb");
        QMessageBox::warning(this, "Ошибка", "Введены не корректные данные." );
        return 0;
    }
    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return 1;
}

int BaseData::get_count_products()
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
    query->exec("SELECT count(*) FROM goods");
    while (query->next()) {
        int count = query->value(0).toString().toInt();
        delete query;
        db.close();
        QSqlDatabase::removeDatabase("mydb");
        return count;
    }
    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return 0;
}

QVector<QVector<QString>> BaseData::get_all()
{
    QVector<QVector<QString>> vec;
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


    QSqlQuery *query = new QSqlQuery(db);
    query->exec("SELECT id, name_goods, cost, count_goods FROM goods");
    while (query->next()) {
        QVector<QString> data;
        data.push_back(query->value(0).toString());
        data.push_back(query->value(1).toString());
        data.push_back(query->value(2).toString());
        data.push_back(query->value(3).toString());
        vec.push_back(data);
    }

    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return vec;
}

QVector<QString> BaseData::get_data_at_id(int id)
{
    QVector<QString> data;
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

    QSqlQuery *query = new QSqlQuery(db);
    query->exec(QString("SELECT name_goods, count_goods, dilivery, cost FROM goods WHERE id = %1").arg(id));
    while (query->next()) {
        data.push_back(query->value(0).toString());
        data.push_back(query->value(1).toString());
        data.push_back(query->value(2).toString());
        data.push_back(query->value(3).toString());
    }

    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return data;

}

bool BaseData::add_order(QVector<QString> data)
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
    QString str = QString("INSERT INTO orders (id_product, count_buy, cost_product, sum_products, id_user) VALUES (%1, %2, %3, %4, %5)").arg(data[0]).arg(data[1]).arg(data[2]).arg(data[3]).arg(data[4]);
    if(!query->exec(str))
    {
        delete query;
        db.close();
        QSqlDatabase::removeDatabase("mydb");
        QMessageBox::warning(this, "Ошибка", "Введены не корректные данные." );
        return 0;
    }
    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return 1;
}

QVector<QVector<QString>> BaseData::get_data_from_orders()
{
    QVector<QVector<QString>> vec;
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


    QSqlQuery *query = new QSqlQuery(db);
    query->exec("SELECT * FROM orders");
    while (query->next()) {
        QVector<QString> data;
        data.push_back(query->value(0).toString());
        data.push_back(query->value(1).toString());
        data.push_back(query->value(2).toString());
        data.push_back(query->value(3).toString());
        data.push_back(query->value(4).toString());
        data.push_back(query->value(5).toString());
        vec.push_back(data);
    }

    delete query;
    db.close();
    QSqlDatabase::removeDatabase("mydb");
    return vec;
}
