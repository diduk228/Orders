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

QTEST_MAIN(MyTest)

#include "tst_mytest.moc"
