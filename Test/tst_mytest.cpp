#include <QtTest>
#include <QCoreApplication>
#include <QObject>
#include <QWidget>
#include "../user.h"
#include "../basedata.h"
#include <QApplication>
// add necessary includes here

class MyTest : public QObject
{
    Q_OBJECT

public:
    MyTest();
    ~MyTest();

private slots:
    void test_get_product_at_id();
    void test_aut();
    void test_get_name_by_id();
    void test_get_picture();
    void test_data_at_login();

};

MyTest::MyTest()
{

}

MyTest::~MyTest()
{

}

void MyTest::test_get_product_at_id()
{
    QWidget *w = new QWidget();
    BaseData bs(w);
    QVector<QString> data = bs.get_data_at_id(19);
    QCOMPARE(data[0], "Кирпич");
    QCOMPARE(data[3], "10");

}

void MyTest::test_aut()
{
    QWidget *w = new QWidget();
    BaseData bs(w);
    QCOMPARE(bs.init_user("da", "das"), 1);
    //delete w;

}

void MyTest::test_get_name_by_id()
{
    QWidget *w = new QWidget();
    BaseData bs(w);
    QCOMPARE(bs.get_name_by_id(2), "fds");
    //delete w;

}

void MyTest::test_get_picture()
{
    QWidget *w = new QWidget();
    BaseData bs(w);
    QCOMPARE(bs.get_picture(19), "C:/Users/danil/Documents/maket/Orders/Goods/кипич.jpg");
}

void MyTest::test_data_at_login()
{
    QWidget *w = new QWidget();
    BaseData bs(w);
    QVector<QString> data = bs.get_data_at_login("da");
    QCOMPARE(data[0], "2");
    QCOMPARE(data[1], "da");
    QCOMPARE(data[2], "das");
    QCOMPARE(data[3], "fds");
    QCOMPARE(data[4], "32");
    QCOMPARE(data[5], "fsd");
    QCOMPARE(data[6], "fds");
    QCOMPARE(data[7], "Manager");
}


QTEST_MAIN(MyTest)

#include "tst_mytest.moc"
