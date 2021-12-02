#ifndef BASEDATA_H
#define BASEDATA_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "user.h"
#include <QMessageBox>
#include <QString>
#include <QtDebug>
#include <QVector>
class BaseData : public User
{
public:
    BaseData(QWidget *parent = nullptr);
    ~BaseData();
    bool init_user(QString name, QString password); // запрос к базе данных
    bool reg_user(QVector<QString> data);           // добавления пользователя в базу данных
    bool add_product(QVector<QString> data);        // Добавляет в базу данных данные о продукте
    int get_count_products();                       // Узнаём сколько товаров в базе
    QVector<QVector<QString>> get_all();            // Получаем все строки с базы
    QVector<QString> get_data_at_id(int id);        // Получаем информация по id
};



#endif // BASEDATA_H
