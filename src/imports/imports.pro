CXX_MODULE = pushnotification
TARGET = declarative_pushnotification
TARGETPATH = QtPushNotification
IMPORT_VERSION = 1.0

QT += qml quick pushnotification pushnotification-private
SOURCES += \
    $$PWD/pushnotification.cpp

load(qml_plugin)

OTHER_FILES += qmldir
