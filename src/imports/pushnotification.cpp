
#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>
#include <QtPushNotification/private/qpushnotification_p.h>

QT_BEGIN_NAMESPACE

class QPushNotificationModule : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")
public:
    void registerTypes(const char *uri)
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("QPushNotification"));

        // @uri QPushNotification
        qmlRegisterType<QPushNotification>(uri, 1, 0, "PushNotification");
    }

    void initializeEngine(QQmlEngine *engine, const char *uri)
    {
        Q_UNUSED(uri);
        Q_UNUSED(engine);
    }
};

QT_END_NAMESPACE

#include "pushnotification.moc"



