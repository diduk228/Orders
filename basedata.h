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
};



#endif // BASEDATA_H
