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
    QVector<QString> get_data_at_id(int id);        // Получаем информация по id в базе товаров
    QVector<QVector<QString>> get_data_from_orders();  // Получаем информацию из таблицы заказов
    bool add_order(QVector<QString> data);          // Добавить заказ в базу
    int get_count_orders();                          // Узнаём сколько заказов
    QString get_name_by_id(int id);                  // Возвращает имя человека по id
    QString get_picture(int id);                     // Возвращает путь к картинки по парамметру
    QVector<QString> get_data_at_login(QString login);  // Получаем данные о пользователе с помощью login'a
    bool req_change_goods(QString id, QString couny_buy);               // Отправляет запрос на изменения таблицы товаров
 };



#endif // BASEDATA_H
