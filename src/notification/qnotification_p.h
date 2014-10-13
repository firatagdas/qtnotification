#ifndef QNOTIFICATION_P_H
#define QNOTIFICATION_P_H

#include <QObject>

QT_BEGIN_NAMESPACE

class QNotification;
class QNotificationParams;

class QNotificationPrivate : public QObject
{
    Q_OBJECT
public:
    QNotificationPrivate(QNotification *q);
    ~QNotificationPrivate();

    virtual void registerId() = 0;
    virtual bool supported() const = 0;
    virtual void send(const QNotificationParams &params) = 0;

    static QNotificationPrivate *createInstance(QNotification *q);

private:
    QString m_senderId;

    Q_DECLARE_PUBLIC(QNotification)
    QNotification *q_ptr;
};

QT_END_NAMESPACE

#endif // QNOTIFICATION_P_H
