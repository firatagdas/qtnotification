ANDROID_BUNDLED_JAR_DEPENDENCIES = \
    jar/QtAndroidNotification-bundled.jar
ANDROID_JAR_DEPENDENCIES = \
    jar/QtAndroidNotification.jar

INCLUDEPATH += $$PWD

PUBLIC_HEADERS += \
    qnotification_global.h \
    qnotification.h \
    qnotificationparams.h

PRIVATE_HEADERS += \
    qnotification_p.h \
    qnotificationparams_p.h

android {
    QT += androidextras

    SOURCES += \
        qnotification.cpp \
        qnotificationparams.cpp
}

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS


