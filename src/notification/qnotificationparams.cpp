#include "qnotificationparams.h"
#include "qnotificationparams_p.h"

QNotificationParamsPrivate::QNotificationParamsPrivate() :
    QObject(0),
    m_autoCancel(false),
    m_defaults(QNotificationParams::DefaultAll),
    m_number(0),
    m_ongoing(false),
    m_onlyAlertOnce(false),
    m_localOnly(false),
    m_groupSummary(false),
    m_useChronometer(false),
    m_when(0),
    m_showWhen(false),
    m_priority(0)
{
}

QNotificationParamsPrivate::~QNotificationParamsPrivate()
{
}

QNotificationParams::QNotificationParams()
    : d_ptr(new QNotificationParamsPrivate())
{
}

QNotificationParams::QNotificationParams(const QNotificationParams &other)
{
    Q_ASSERT(other.d_ptr->ref.ref());
    d_ptr = other.d_ptr;
}

QNotificationParams::~QNotificationParams()
{
    if (!d_ptr->ref.deref())
        delete d_ptr;
}

void QNotificationParams::setAutoCancel(bool autoCancel)
{
    Q_D(QNotificationParams);
    d->m_autoCancel = autoCancel;
}

bool QNotificationParams::autoCancel() const
{
    Q_D(const QNotificationParams);
    return d->m_autoCancel;
}

void QNotificationParams::setContentInfo(const QString &contentInfo)
{
    Q_D(QNotificationParams);
    d->m_contentInfo = contentInfo;
}

QString QNotificationParams::contentInfo() const
{
    Q_D(const QNotificationParams);
    return d->m_contentInfo;
}

void QNotificationParams::setContentText(const QString &contentText)
{
    Q_D(QNotificationParams);
    d->m_contentText = contentText;
}

QString QNotificationParams::contentText() const
{
    Q_D(const QNotificationParams);
    return d->m_contentText;
}

void QNotificationParams::setContentTitle(const QString &contentTitle)
{
    Q_D(QNotificationParams);
    d->m_contentTitle = contentTitle;
}

QString QNotificationParams::contentTitle() const
{
    Q_D(const QNotificationParams);
    return d->m_contentTitle;
}

void QNotificationParams::setDefaults(int defaults)
{
    Q_D(QNotificationParams);
    d->m_defaults = defaults;
}

int QNotificationParams::defaults() const
{
    Q_D(const QNotificationParams);
    return d->m_defaults;
}

void QNotificationParams::setNumber(int number)
{
    Q_D(QNotificationParams);
    d->m_number = number;
}

int QNotificationParams::number() const
{
    Q_D(const QNotificationParams);
    return d->m_number;
}

void QNotificationParams::setLights(int argb, int onMs, int offMs)
{
    Q_D(QNotificationParams);
    d->m_lightInfo.argb = argb;
    d->m_lightInfo.onMs = onMs;
    d->m_lightInfo.offMs = offMs;
}

void QNotificationParams::setLights(const QNotificationParams::LightInfo &lightInfo)
{
    Q_D(QNotificationParams);
    d->m_lightInfo = lightInfo;
}

QNotificationParams::LightInfo QNotificationParams::lights() const
{
    Q_D(const QNotificationParams);
    return d->m_lightInfo;
}

void QNotificationParams::setOngoing(bool ongoing)
{
    Q_D(QNotificationParams);
    d->m_ongoing = ongoing;
}

bool QNotificationParams::ongoing() const
{
    Q_D(const QNotificationParams);
    return d->m_ongoing;
}

void QNotificationParams::setOnlyAlertOnce(bool onlyAlertOnce)
{
    Q_D(QNotificationParams);
    d->m_onlyAlertOnce = onlyAlertOnce;
}

bool QNotificationParams::onlyAlertOnce() const
{
    Q_D(const QNotificationParams);
    return d->m_onlyAlertOnce;
}

void QNotificationParams::setSmallIcon(const QString &rDrawPath)
{
    Q_D(QNotificationParams);
    d->m_smallIcon = rDrawPath;
}

QString QNotificationParams::smallIcon() const
{
    Q_D(const QNotificationParams);
    return d->m_smallIcon;
}

void QNotificationParams::setLargeIcon(const QString &rDrawPath)
{
    Q_D(QNotificationParams);
    d->m_largeIcon = rDrawPath;
}

QString QNotificationParams::largeIcon() const
{
    Q_D(const QNotificationParams);
    return d->m_largeIcon;
}

void QNotificationParams::setLocalOnly(bool localOnly)
{
    Q_D(QNotificationParams);
    d->m_localOnly = localOnly;
}

bool QNotificationParams::localOnly() const
{
    Q_D(const QNotificationParams);
    return d->m_localOnly;
}

void QNotificationParams::setGroup(const QString &groupKey)
{
    Q_D(QNotificationParams);
    d->m_group = groupKey;
}

QString QNotificationParams::group() const
{
    Q_D(const QNotificationParams);
    return d->m_group;
}

void QNotificationParams::setGroupSummary(bool groupSummary)
{
    Q_D(QNotificationParams);
    d->m_groupSummary = groupSummary;
}

bool QNotificationParams::groupSummary() const
{
    Q_D(const QNotificationParams);
    return d->m_groupSummary;
}

void QNotificationParams::setSortKey(const QString &sortKey)
{
    Q_D(QNotificationParams);
    d->m_sortKey = sortKey;
}

QString QNotificationParams::sortKey() const
{
    Q_D(const QNotificationParams);
    return d->m_sortKey;
}

void QNotificationParams::setSound(const QString &rRawPath)
{
    Q_D(QNotificationParams);
    d->m_sound = rRawPath;
}

QString QNotificationParams::sound() const
{
    Q_D(const QNotificationParams);
    return d->m_sound;
}

void QNotificationParams::setStyle(QNotificationParams::Style style)
{
    Q_D(QNotificationParams);
    d->m_style = style;
}

QNotificationParams::Style QNotificationParams::style() const
{
    Q_D(const QNotificationParams);
    return d->m_style;
}

void QNotificationParams::setSubText(const QString &subText)
{
    Q_D(QNotificationParams);
    d->m_subText = subText;
}

QString QNotificationParams::subText() const
{
    Q_D(const QNotificationParams);
    return d->m_subText;
}

void QNotificationParams::setTicker(const QString &ticker)
{
    Q_D(QNotificationParams);
    d->m_ticker = ticker;
}

QString QNotificationParams::ticker() const
{
    Q_D(const QNotificationParams);
    return d->m_ticker;
}

void QNotificationParams::setUsesChronometer(bool useChronometer)
{
    Q_D(QNotificationParams);
    d->m_useChronometer = useChronometer;
}

bool QNotificationParams::usesChronometer() const
{
    Q_D(const QNotificationParams);
    return d->m_useChronometer;
}

void QNotificationParams::setVibrate(QList<qlonglong> vibrate)
{
    Q_D(QNotificationParams);
    d->m_vibrate = vibrate;
}

QList<qlonglong> QNotificationParams::vibrate() const
{
    Q_D(const QNotificationParams);
    return d->m_vibrate;
}

void QNotificationParams::setWhen(qlonglong when)
{
    Q_D(QNotificationParams);
    d->m_when = when;
}

qlonglong QNotificationParams::when() const
{
    Q_D(const QNotificationParams);
    return d->m_when;
}

void QNotificationParams::setShowWhen(bool show)
{
    Q_D(QNotificationParams);
    d->m_showWhen = show;
}

bool QNotificationParams::showWhen() const
{
    Q_D(const QNotificationParams);
    return d->m_showWhen;
}

void QNotificationParams::setPriority(int priority)
{
    Q_D(QNotificationParams);
    d->m_priority = priority;
}

int QNotificationParams::priority() const
{
    Q_D(const QNotificationParams);
    return d->m_priority;
}

void QNotificationParams::setProgress(int max, int progress, bool indeterminate)
{
    Q_D(QNotificationParams);
    d->m_progressInfo.max = max;
    d->m_progressInfo.progress = progress;
    d->m_progressInfo.indeterminate = indeterminate;
}

void QNotificationParams::setProgress(const QNotificationParams::ProgressInfo &progressInfo)
{
    Q_D(QNotificationParams);
    d->m_progressInfo = progressInfo;
}

QNotificationParams::ProgressInfo QNotificationParams::progress() const
{
    Q_D(const QNotificationParams);
    return d->m_progressInfo;
}

QNotificationParams &QNotificationParams::operator=(const QNotificationParams &other)
{
    Q_ASSERT(other.d_ptr->ref.ref());
    Q_D(QNotificationParams);

    if (!d->ref.deref())
        delete d_ptr;

    d_ptr = other.d_ptr;

    return *this;
}

bool QNotificationParams::operator==(const QNotificationParams &other) const
{
    Q_D(const QNotificationParams);
    QNotificationParamsPrivate *o = other.d_ptr;

    if (d->m_autoCancel != o->m_autoCancel)
        return false;
    else if (d->m_contentInfo != o->m_contentInfo)
        return false;
    else if (d->m_contentText != o->m_contentText)
        return false;
    else if (d->m_contentTitle != o->m_contentTitle)
        return false;
    else if (d->m_defaults != o->m_defaults)
        return false;
    else if (d->m_group != o->m_group)
        return false;
    else if (d->m_groupSummary != o->m_groupSummary)
        return false;
    else if (d->m_largeIcon != o->m_largeIcon)
        return false;
    else if (d->m_lightInfo.argb != o->m_lightInfo.argb
             && d->m_lightInfo.onMs != o->m_lightInfo.onMs
             && d->m_lightInfo.offMs != o->m_lightInfo.offMs)
        return false;
    else if (d->m_localOnly != o->m_localOnly)
        return false;
    else if (d->m_number != o->m_number)
        return false;
    else if (d->m_ongoing != o->m_ongoing)
        return false;
    else if (d->m_onlyAlertOnce != o->m_onlyAlertOnce)
        return false;
    else if (d->m_priority != o->m_priority)
        return false;
    else if (d->m_progressInfo.max != o->m_progressInfo.max
             && d->m_progressInfo.progress != o->m_progressInfo.progress
             && d->m_progressInfo.indeterminate != o->m_progressInfo.indeterminate)
        return false;
    else if (d->m_showWhen != o->m_showWhen)
        return false;
    else if (d->m_smallIcon != o->m_smallIcon)
        return false;
    else if (d->m_sortKey != o->m_sortKey)
        return false;
    else if (d->m_sound != o->m_sound)
        return false;
    else if (d->m_style != o->m_style)
        return false;
    else if (d->m_subText != o->m_subText)
        return false;
    else if (d->m_ticker != o->m_ticker)
        return false;
    else if (d->m_useChronometer != o->m_useChronometer)
        return false;
    else if (d->m_vibrate != o->m_vibrate)
        return false;
    else if (d->m_when != o->m_when)
        return false;

    return true;
}

bool QNotificationParams::operator!=(const QNotificationParams &other) const
{
    return !(*this == other);
}
