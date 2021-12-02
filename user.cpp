#include "user.h"
User::User(QString mod, QString name, QString adress, int phone, QString name_person, QString login, QString password, QWidget *parent) : QMainWindow(parent), m_mod(mod),
    m_name(name), m_adress(adress), m_phone(phone), m_name_person(name_person), m_login(login), m_password(password)
{

}

QString User::get_mod()
{
    return m_mod;
}

QString User::get_name()
{
    return m_name;
}

QString User::get_adress()
{
    return m_adress;
}

QString User::get_phone()
{
    return m_phone;
}

QString User::get_name_person()
{
    return m_name_person;
}

QString User::get_login()
{
    return m_login;
}

QString User::get_password()
{
    return m_password;
}

void User::set_user(QString mod, QString name, QString adress, QString phone, QString name_person, QString login, QString password)
{
    m_mod = mod;
    m_name = name;
    m_adress = adress;
    m_phone = phone;
    m_name_person = name_person;
    m_login = login;
    m_password = password;
}
