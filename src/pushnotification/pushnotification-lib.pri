ANDROID_BUNDLED_JAR_DEPENDENCIES = \
    jar/QtAndroidPushNotification-bundled.jar
ANDROID_JAR_DEPENDENCIES = \
    jar/QtAndroidPushNotification.jar

INCLUDEPATH += $$PWD

PUBLIC_HEADERS += \
    qpushnotification_global.h

PRIVATE_HEADERS += \
    qpushnotification_p.h

android {
    QT += androidextras
    LIBS += -ljnigraphics

    SOURCES += \
        qpushnotification.cpp
}

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS

