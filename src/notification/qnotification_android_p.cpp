#include "qnotification_android_p.h"
#include "qnotificationparams.h"

static const char qtAndroidPushNotificationClass[] = "org/qtproject/qt5/android/QtNotification";
static bool initializedJava = false;

QNotificationPrivate::createInstance(QNotification *q)
{
    return new QAndroidNotificationPrivate(q);
}

QAndroidNotificationPrivate::QAndroidNotificationPrivate(QNotification *q) :
    QNotificationPrivate(q),
    m_id(reinterpret_cast<quintptr>(this))
{
    if (!initializedJava) {
        QAndroidJniObject::setStaticField<jobject>(
                    qtAndroidPushNotificationClass, "m_activity", QtAndroid::androidActivity().object());
        initializedJava = true;
    }

    m_notification = QAndroidJniObject(qtAndroidPushNotificationClass,
                                       "(J)V", m_id);
}

QAndroidNotificationPrivate::~QAndroidNotificationPrivate()
{

}

void QAndroidNotificationPrivate::registerId()
{
    m_notification.callMethod<void>("registerId");
}

void QAndroidNotificationPrivate::send(const QNotificationParams &params)
{
    m_notificationBuilder = QAndroidJniObject("android/support/v4/app/NotificationCompat/Builder");
    m_notificationBuilder.callMethod<void>("setAutoCancel", "(Z)V", params.autoCancel());

    if (!params.contentInfo().isEmpty())
        m_notificationBuilder.callMethod<void>("setContentInfo",
                                               "(Ljava/lang/String;)V",
                                               QAndroidJniObject::fromString(params.contentInfo()));
    if (!params.contentText().isEmpty())
        m_notificationBuilder.callMethod<void>("setContentText",
                                               "(Ljava/lang/String;)V",
                                               QAndroidJniObject::fromString(params.contentText()));

    if (!params.contentTitle().isEmpty())
        m_notificationBuilder.callMethod<void>("setContentTitle",
                                               "(Ljava/lang/String;)V",
                                               QAndroidJniObject::fromString(params.contentTitle()));

    m_notificationBuilder.callMethod<jint>("setDefaults", "(I)V", params.defaults());

}

bool QAndroidNotificationPrivate::supported() const
{

}
