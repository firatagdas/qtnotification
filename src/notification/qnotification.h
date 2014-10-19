#ifndef QNOTIFICATION_H
#define QNOTIFICATION_H

#include <QObject>
#include "qnotification_global.h"
#include "qnotification_p.h"
#include "qnotificationparams.h"
#include <QMessageLogger>

QT_BEGIN_NAMESPACE

Q_DECLARE_LOGGING_CATEGORY(QtNotificationLogging)

class Q_NOTIFICATION_EXPORT QNotification : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString senderId READ senderId WRITE setSenderId NOTIFY senderIdChanged)
public:
    QNotification(QObject *parent = 0);
    ~QNotification();

    QString senderId() const;
    void setSenderId(const QString &senderId);

Q_SIGNALS:
    void senderIdChanged();

public Q_SLOTS:
    void registerId();
    void send(const QNotificationParams &params);
    bool supported() const;

private:
    Q_DECLARE_PRIVATE(QNotification)
    QNotificationPrivate *d_ptr;
};

QT_END_NAMESPACE

#endif // QNOTIFICATION_H
