package org.qtproject.qt5.android;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.support.v4.content.WakefulBroadcastReceiver;

public class QtGcmBroadcastReceiver extends WakefulBroadcastReceiver
{
    @Override
    public void onReceive(Context context, Intent intent)
    {
        ComponentName component = new ComponentName(context.getPackageName(), QtGcmIntentService.class.getName());
        startWakefulService(context, intent.setComponent(component));
        setResultCode(Activity.RESULT_OK);
    }

    public void unregisterReceiver()
    {
        if (QtPushNotification.m_activity != null)
            QtPushNotification.m_activity.unregisterReceiver(this);
    }
}
