#ifndef QNOTIFICATION_ANDROID_P_H
#define QNOTIFICATION_ANDROID_P_H

#include "qnotification_p.h"
#include <QtAndroidExtras>

class QAndroidNotificationPrivate : QNotificationPrivate
{
    Q_OBJECT
public:
    QAndroidNotificationPrivate(QNotification *q);
    virtual ~QAndroidNotificationPrivate();

    void registerId();
    bool supported() const;
    void send(const QNotificationParams &params);

private:
    quintptr m_id;
    QAndroidJniObject m_notification;
    QAndroidJniObject m_notificationBuilder;
};

#endif // QNOTIFICATION_ANDROID_P_H
