#ifndef QNOTIFICATIONPARAMS_H
#define QNOTIFICATIONPARAMS_H

#include <QtCore>

class QNotificationParamsPrivate;

class QNotificationParams
{
public:
    typedef struct _LightInfo {
        int argb;
        int onMs;
        int offMs;
        _LightInfo() : argb(0), onMs(0), offMs(0) {}
    } LightInfo;

    typedef struct _ProgressInfo {
        int max;
        int progress;
        bool indeterminate;
        _ProgressInfo() : max(0), progress(0), indeterminate(false) {}
    } ProgressInfo;

    enum Style {
        DefaultStyle,
        BigTextStyle,
        BigPictureStyle,
        InboxStyle
    };

    enum Default {
        DefaultSound = 1,
        DefaultVibrate = 2,
        DefaultLights = 4,
        DefaultAll = 7
    };

    QNotificationParams();
    explicit QNotificationParams(const QNotificationParams &other);

    ~QNotificationParams();

    void setAutoCancel(bool autoCancel);
    bool autoCancel() const;

    void setContentInfo(const QString &contentInfo);
    QString contentInfo() const;

    void setContentText(const QString &contentText);
    QString contentText() const;

    void setContentTitle(const QString &contentTitle);
    QString contentTitle() const;

    void setDefaults(int defaults);
    int defaults() const;

    void setNumber(int number);
    int number() const;

    void setLights(int argb, int onMs, int offMs);
    void setLights(const LightInfo &lightInfo);
    LightInfo lights() const;

    void setOngoing(bool ongoing);
    bool ongoing() const;

    void setOnlyAlertOnce(bool onlyAlertOnce);
    bool onlyAlertOnce() const;

    void setSmallIcon(const QString &rDrawPath);
    QString smallIcon() const;

    void setLargeIcon(const QString &rDrawPath);
    QString largeIcon() const;

    void setLocalOnly(bool localOnly);
    bool localOnly() const;

    void setGroup(const QString &groupKey);
    QString group() const;

    void setGroupSummary(bool groupSummary);
    bool groupSummary() const;

    void setSortKey(const QString &sortKey);
    QString sortKey() const;

    void setSound(const QString &rRawPath);
    QString sound() const;

    void setStyle(Style style);
    Style style() const;

    void setSubText(const QString &subText);
    QString subText() const;

    void setTicker(const QString &ticker);
    QString ticker() const;

    void setUsesChronometer(bool useChronometer);
    bool usesChronometer() const;

    void setVibrate(QList<qlonglong> vibrate);
    QList<qlonglong> vibrate() const;

    void setWhen(qlonglong when);
    qlonglong when() const;

    void setShowWhen(bool show);
    bool showWhen() const;

    void setPriority(int priority);
    int priority() const;

    void setProgress(int max, int progress, bool indeterminate);
    void setProgress(const ProgressInfo &progressInfo);
    ProgressInfo progress() const;

    QNotificationParams &operator=(const QNotificationParams &other);
    bool operator==(const QNotificationParams &other) const;
    bool operator!=(const QNotificationParams &other) const;

private:
    Q_DECLARE_PRIVATE(QNotificationParams)
    QNotificationParamsPrivate *d_ptr;
};

#endif // QNOTIFICATIONPARAMS_H
