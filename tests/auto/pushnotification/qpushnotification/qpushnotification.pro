CONFIG += testcase parallel_test
TARGET = tst_qpushnotification
osx:CONFIG -= app_bundle

QT += pushnotification pushnotification-private testlib
SOURCES += \
    tst_qpushnotification.cpp
