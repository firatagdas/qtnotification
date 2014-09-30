#include <QtTest/QtTest>
#include <QtCore/qstandardpaths.h>
#include <QtCore/qdir.h>
#include <QtCore/qtemporarydir.h>
#include <QtCore/qfileinfo.h>
#include <QtPushNotification/private/qpushnotification_p.h>

class tst_QPushNotification : public QObject
{
    Q_OBJECT
public:
    tst_QPushNotification();

private slots:
    void initTestCase();
};

void tst_QPushNotification::initTestCase()
{
}


QTEST_MAIN(tst_QPushNotification)

#include "tst_pushnotification.moc"
