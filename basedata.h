#ifndef BASEDATA_H
#define BASEDATA_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "user.h"
#include <QMessageBox>
#include <QString>
#include <QtDebug>
class BaseData : public User
{
public:
    BaseData();
    bool init_user(QString name, QString password);
};

#endif // BASEDATA_H
