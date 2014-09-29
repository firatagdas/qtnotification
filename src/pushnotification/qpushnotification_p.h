#ifndef QPUSHNOTIFICATION_P_H
#define QPUSHNOTIFICATION_P_H

#include "qpushnotification_global.h"
#include <QQuickItem>

class QPushNotificationPrivate : public QObject
{
    Q_OBJECT
public:
    QPushNotificationPrivate(QObject *parent = 0);
    QString m_senderId;
};

class Q_PUSHNOTIFICATION_EXPORT QPushNotification : public QQuickItem
{
    Q_OBJECT
public:
    QPushNotification(QQuickItem *parent = 0);
    ~QPushNotification();

private:
    Q_DECLARE_PRIVATE(QPushNotification)
    QPushNotificationPrivate *d_ptr;
};

#endif // QPUSHNOTIFICATION_P_H
