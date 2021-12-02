#include "user.h"
User::User (QString mod, QString name, QString adress, QString phone, QString name_person, QString login, QString password, QWidget *parent) :  QMainWindow(parent),   m_mod(mod),
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

int User::get_id()
{
    return m_id;
}

void User::set_user(int id,QString mod, QString name, QString adress, QString phone, QString name_person, QString login, QString password)
{
    m_id = id;
    m_mod = mod;
    m_name = name;
    m_adress = adress;
    m_phone = phone;
    m_name_person = name_person;
    m_login = login;
    m_password = password;
}

void User::save_user()
{
    QTextStream out(stdout);

    // Создаем объект класса QFile и связываем его с указанным именем файла
    QString filename = "C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\user.txt";
    QFile file(filename);

    // Открываем файл в режиме "Только для записи"
    if (file.open(QIODevice::WriteOnly)) {
      QTextStream out(&file); // поток записываемых данных направляем в файл
      out << m_id << "\n";
      out << m_mod << "\n";
      out << m_name << "\n";
      out << m_adress << "\n";
      out << m_phone << "\n";
      out << m_name_person << "\n";
      out << m_login << "\n";
      out << m_password;

      qWarning("Could not open file");
    }
    // Закрываем файл
    file.close();
}

void User::set_cucki()
{

    // Создаем объект
    QFile file("C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\mainwindow_ids.txt");

    // С помощью метода open() открываем файл в режиме чтения
    if (!file.open(QIODevice::ReadOnly)) {
      qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
      return;
    }

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);
    // Считываем файл строка за строкой
    QVector<QString> vec;
    for(int i = 0; i < 8; i++) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
      QString line = in.readLine(); // метод readLine() считывает одну строку из потока
       vec.push_back(line);
    }
    set_user(vec[0].toInt(),vec[1],vec[2],vec[3],vec[4], vec[5], vec[6], vec[7]);

    // Закрываем файл
    file.close();
}

