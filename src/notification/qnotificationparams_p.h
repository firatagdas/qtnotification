#ifndef QNOTIFICATIONPARAMS_P_H
#define QNOTIFICATIONPARAMS_P_H

#include <QObject>
#include "qnotificationparams.h"

class QNotificationParamsPrivate : public QObject
{
    Q_OBJECT
public:
    QNotificationParamsPrivate();
    ~QNotificationParamsPrivate();


private:
    QAtomicInt ref;
    bool m_autoCancel;
    QString m_contentInfo;
    QString m_contentText;
    QString m_contentTitle;
    int m_defaults;
    int m_number;
    QNotificationParams::LightInfo m_lightInfo;
    bool m_ongoing;
    bool m_onlyAlertOnce;
    QString m_smallIcon;
    QString m_largeIcon;
    bool m_localOnly;
    QString m_group;
    bool m_groupSummary;
    QString m_sortKey;
    QString m_sound;
    QNotificationParams::Style m_style;
    QString m_subText;
    QString m_ticker;
    bool m_useChronometer;
    QList<qlonglong> m_vibrate;
    qlonglong m_when;
    bool m_showWhen;
    int m_priority;
    QNotificationParams::ProgressInfo m_progressInfo;

    friend class QNotificationParams;
};

#endif // QNOTIFICATIONPARAMS_P_H
