
#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>
#include <QtNotification/qnotification.h>

QT_BEGIN_NAMESPACE

class QNotificationModule : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")
public:
    void registerTypes(const char *uri)
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("QNotification"));

        // @uri QNotification
        qmlRegisterType<QNotification>(uri, 1, 0, "Notification");
    }

    void initializeEngine(QQmlEngine *engine, const char *uri)
    {
        Q_UNUSED(uri);
        Q_UNUSED(engine);
    }
};

QT_END_NAMESPACE

#include "notification.moc"



