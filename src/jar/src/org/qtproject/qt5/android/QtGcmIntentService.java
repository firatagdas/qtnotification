package org.qtproject.qt5.android;

import android.app.IntentService;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.NotificationCompat;
import android.util.Log;
import com.google.android.gms.gcm.GoogleCloudMessaging;

public class QtGcmIntentService extends IntentService
{
    public static final String TAG = "QtGcmIntentService";

    public QtGcmIntentService()
    {
        super("QtGcmIntentService");
    }

    @Override
    protected void onHandleIntent(Intent intent)
    {
        Bundle extras = intent.getExtras();
        GoogleCloudMessaging googleCloudMessaging = GoogleCloudMessaging.getInstance(this);
        String messageType = googleCloudMessaging.getMessageType(intent);

        if (!extras.isEmpty()) {
            if (messageType.equals(GoogleCloudMessaging.MESSAGE_TYPE_SEND_ERROR)) {
                sendNotification("Message type send error: " + extras.toString());
            } else if (messageType.equals(GoogleCloudMessaging.MESSAGE_TYPE_DELETED)) {
                sendNotification("Message deleted on server: " + extras.toString());
            } else {
                sendNotification("Data Received: " + extras.toString());
            }
        } else {
            sendNotification("Extras is empty.");
        }

        QtGcmBroadcastReceiver.completeWakefulIntent(intent);
    }

    private void sendNotification(String message)
    {
        Log.d(TAG, message);

        NotificationManager notificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

        Context context = getApplicationContext();
        Intent intent = context.getPackageManager().getLaunchIntentForPackage(context.getPackageName());
        intent.addCategory(Intent.CATEGORY_LAUNCHER);
        intent.setAction(Intent.ACTION_MAIN);

        PendingIntent contentIntent = PendingIntent.getActivity(this, 0, intent, 0);

        NotificationCompat.Builder builder = new NotificationCompat.Builder(this);
        builder.setContentTitle("Test Push Notification")
               .setContentText(message);

        builder.setContentIntent(contentIntent);
        notificationManager.notify(1, builder.build());
    }
}
