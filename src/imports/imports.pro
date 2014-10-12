CXX_MODULE = notification
TARGET = declarative_notification
TARGETPATH = QtNotification
IMPORT_VERSION = 1.0

QT += qml quick notification notification-private
SOURCES += \
    $$PWD/notification.cpp

load(qml_plugin)

OTHER_FILES += qmldir
