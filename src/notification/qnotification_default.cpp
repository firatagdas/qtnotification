#include "qnotification_default_p.h"
#include "qnotification.h"

QT_BEGIN_NAMESPACE

QNotificationPrivateDefault::QNotificationPrivateDefault(QNotification *q)
    : q_ptr(q)
{
}

QNotificationPrivateDefault::setSenderId(const QString &senderId)
{
}

QString QNotificationPrivateDefault::senderId() const
{
    return QString();
}

QT_END_NAMESPACE
