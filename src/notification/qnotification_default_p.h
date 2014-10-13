#ifndef QNOTIFICATION_DEFAULT_P_H
#define QNOTIFICATION_DEFAULT_P_H

#include "qnotification_p.h"

QT_BEGIN_NAMESPACE

class QNotification;

class QNotificationPrivateDefault : public QNotificationPrivate
{
    Q_OBJECT
public:
    QNotificationPrivateDefault(QNotification *q);
    virtual ~QNotificationPrivateDefault();

    void registerId();
    bool supported() const;
    void send(const QNotificationParams &params);
};

QT_END_NAMESPACE

#endif // QNOTIFICATION_DEFAULT_P_H
