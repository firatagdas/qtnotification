load(qt_build_paths)
CONFIG += java
DESTDIR = $$MODULE_BASE_OUTDIR/jar
SDK_ROOT = $$(ANDROID_SDK_ROOT)

# this is a bug. that should be fixed...
DIRLIST_SEP = ":"

JAVACLASSPATH += \
    $$SDK_ROOT/extras/android/support/v4/android-support-v4.jar \
    $$SDK_ROOT/extras/google/google_play_services/libproject/google-play-services_lib/libs/google-play-services.jar

JAVACLASSPATH += $$PWD/src

JAVASOURCES += \
    $$PWD/src/org/qtproject/qt5/android/QtNotification.java \
    $$PWD/src/org/qtproject/qt5/android/QtGcmBroadcastReceiver.java \
    $$PWD/src/org/qtproject/qt5/android/QtGcmIntentService.java

# install
target.path = $$[QT_INSTALL_PREFIX]/jar
INSTALLS += target
