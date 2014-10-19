#include "qnotification_p.h"
#include "qnotification.h"

Q_LOGGING_CATEGORY(QtNotificationLogging, "QtNotification")

QNotificationPrivate::QNotificationPrivate(QNotification *q)
    : QObject(0), q_ptr(q)
{
}

QNotificationPrivate::~QNotificationPrivate()
{
}

void QNotificationPrivate::registerId()
{
}

void QNotificationPrivate::send(const QNotificationParams &params)
{
    Q_UNUSED(params);
}

bool QNotificationPrivate::supported() const
{
    return false;
}

QNotification::QNotification(QObject *parent)
    : QObject(parent), d_ptr(0)
{
}

QNotification::~QNotification()
{
    delete d_ptr;
}

QString QNotification::senderId() const
{
    Q_D(const QNotification);
    return d->m_senderId;
}

void QNotification::setSenderId(const QString &senderId)
{
    Q_D(QNotification);
    if (d->m_senderId == senderId)
        return;

    d->m_senderId = senderId;
}

void QNotification::registerId()
{
    Q_D(QNotification);
    d->registerId();
}

void QNotification::send(const QNotificationParams &params)
{
    Q_D(QNotification);
    d->send(params);
}

bool QNotification::supported() const
{
    Q_D(const QNotification);
    return d->supported();
}
