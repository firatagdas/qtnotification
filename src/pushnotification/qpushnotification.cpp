#include "qpushnotification_p.h"

QPushNotificationPrivate::QPushNotificationPrivate(QObject *parent)
    : QObject(parent)
{
}

QPushNotification::QPushNotification(QQuickItem *parent)
    : QQuickItem(parent), d_ptr(new QPushNotificationPrivate())
{
}

QPushNotification::~QPushNotification()
{
    delete d_ptr;
}
