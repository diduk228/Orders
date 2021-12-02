#ifndef USER_H
#define USER_H
#include <QWidget>
#include <QString>
#include <QMainWindow>


class User : public QMainWindow
{
public:
    User(QString mod, QString name, QString adress, QString phone, QString name_person, QString login, QString password, QWidget *parent = 0);
private:
    QString m_mod = nullptr;
    QString m_name;
    QString m_adress;
    QString m_phone;
    QString m_name_person;
    QString m_login;
    QString m_password;
public:
    QString get_mod();
    QString get_name();
    QString get_adress();
    QString get_phone();
    QString get_name_person();
    QString get_login();
    QString get_password();
    void set_user(QString mod, QString name, QString adress, QString phone, QString name_person, QString login, QString password);
};

#endif // USER_H
