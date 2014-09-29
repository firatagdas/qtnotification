package org.qtproject.qt5.android;


import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.gcm.GoogleCloudMessaging;

import java.io.IOException;

public class QtPushNotification
{
    private static final String GCM_REGISTER_ID = "registration_id";
    private static final String GCM_APP_VERSION = "appVersion";

    public static Activity m_activity;
    public static long m_delegate;

    private GoogleCloudMessaging m_googleCloudMessaging;

    public QtPushNotification()
    {
        if (m_activity == null)
            return;

        if (checkPlayService())
            m_googleCloudMessaging = GoogleCloudMessaging.getInstance(m_activity);
    }

    private boolean checkPlayService()
    {
        int resultCode = GooglePlayServicesUtil.isGooglePlayServicesAvailable(m_activity.getApplicationContext());
        if (resultCode != ConnectionResult.SUCCESS) {
            if (GooglePlayServicesUtil.isUserRecoverableError(resultCode)) {
                GooglePlayServicesUtil.getErrorDialog(resultCode, m_activity, 9000).show();
            }

            return false;
        }

        return true;
    }

    private int getAppVersion()
    {
        try {
            Context context = m_activity.getApplicationContext();
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(context.getPackageName(), 0);

            return packageInfo.versionCode;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return -1;
        }
    }

    private SharedPreferences getSharedPreferences()
    {
        return m_activity.getSharedPreferences(m_activity.getClass().getSimpleName(), Context.MODE_PRIVATE);
    }

    public String registerId(String senderId)
    {
        final SharedPreferences preferences = getSharedPreferences();
        boolean gotRegisterId = false;

        String registerId = preferences.getString(GCM_REGISTER_ID, "");
        if (!registerId.isEmpty()) {
            int registeredVersion = preferences.getInt(GCM_APP_VERSION, Integer.MIN_VALUE);
            int currentVersion = getAppVersion();
            if (registeredVersion == currentVersion) {
                gotRegisterId = true;
            }
        }

        if (!gotRegisterId) {
            try {
                registerId = m_googleCloudMessaging.register(senderId);

                int appVersion = getAppVersion();

                SharedPreferences.Editor editor = preferences.edit();
                editor.putString(GCM_REGISTER_ID, registerId);
                editor.putInt(GCM_APP_VERSION, appVersion);
                editor.commit();

            } catch (IOException e) {
                e.printStackTrace();
                registerId = "";
            }
        }

        return registerId;
    }
}
