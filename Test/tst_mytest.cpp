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
    void test_case1();
    void test_aut();

};

MyTest::MyTest()
{

}

MyTest::~MyTest()
{

}

void MyTest::test_case1()
{

    QWidget *w = new QWidget();
    BaseData bs(w);
    QCOMPARE(bs.get_count_products(), 5);
    //delete w;

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
