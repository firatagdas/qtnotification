#include "qnotification_android_p.h"
#include "qnotificationparams.h"
#include "qnotification.h"

static const char qtAndroidPushNotificationClass[] = "org/qtproject/qt5/android/QtNotification";
static bool initializedJava = false;

QNotificationPrivate *QNotificationPrivate::createInstance(QNotification *q)
{
    return new QAndroidNotificationPrivate(q);
}

QAndroidNotificationPrivate::QAndroidNotificationPrivate(QNotification *q) :
    QNotificationPrivate(q),
    m_id(reinterpret_cast<quintptr>(this))
{
    QAndroidJniEnvironment env;
    jclass pushNotificationClass = env->FindClass(qtAndroidPushNotificationClass);
    if (!pushNotificationClass) {
        qCCritical(QtNotificationLogging) << qtAndroidPushNotificationClass << "class could not found.";
        return;
    }

    if (!initializedJava) {
        QAndroidJniObject::setStaticField<jobject>(
                    pushNotificationClass, "m_activity",
                    "Lorg/qtproject/qt5/android/bindings/QtActivity;",
                    QtAndroid::androidActivity().object());
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
                                               QAndroidJniObject::fromString(params.contentInfo()).object());
    if (!params.contentText().isEmpty())
        m_notificationBuilder.callMethod<void>("setContentText",
                                               "(Ljava/lang/String;)V",
                                               QAndroidJniObject::fromString(params.contentText()).object());

    if (!params.contentTitle().isEmpty())
        m_notificationBuilder.callMethod<void>("setContentTitle",
                                               "(Ljava/lang/String;)V",
                                               QAndroidJniObject::fromString(params.contentTitle()).object());

    m_notificationBuilder.callMethod<jint>("setDefaults", "(I)V", params.defaults());

}

bool QAndroidNotificationPrivate::supported() const
{
    return QtAndroid::androidSdkVersion() > 9 ? true : false;
}
