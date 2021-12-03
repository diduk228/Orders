QT += testlib
QT += gui widgets
QT += sql
#CONFIG += testlib
include(../common.pri)

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    tst_mytest.cpp

HEADERS +=
