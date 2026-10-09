package com.oppo.engineermode;

import android.app.Activity;
import android.os.Bundle;
import android.os.PowerManager;
import android.os.SystemClock;
import android.widget.Toast;
import com.oppo.engineermode.util.k0;
import com.oppo.engineermode.util.u0;
import com.oppo.engineermode.util.v;

/* loaded from: classes.dex */
public class RebootManager extends Activity {
    @Override // android.app.Activity
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        PowerManager powerManager = (PowerManager) getSystemService("power");
        String stringExtra = getIntent().getStringExtra("order");
        v.e("RebootManager", "RebootManager : " + stringExtra);
        if (stringExtra == null || !stringExtra.equals("*#3644321#")) {
            if (stringExtra == null || !stringExtra.equals("*#3644999#")) {
                v.e("RebootManager", "do nothing");
                return;
            }
            if (!com.oppo.engineermode.util.a.b()) {
                v.e("RebootManager", "already config done");
                Toast.makeText(this, "already config done", 1).show();
                finish();
                return;
            } else if (com.oppo.engineermode.util.a.c()) {
                SystemClock.sleep(200L);
                powerManager.reboot("reboot_eng");
                return;
            } else {
                v.e("RebootManager", "reset partion protect failed");
                Toast.makeText(this, "reset partion protect failed", 1).show();
                finish();
                return;
            }
        }
        if (!k0.d() || k0.b(4)) {
            v.e("RebootManager", "decrypt first");
            Toast.makeText(this, "decrypt first", 1).show();
            finish();
            return;
        }
        v.e("RebootManager", "isPartionWriteProtectDisabled = " + com.oppo.engineermode.util.a.b());
        com.oppo.engineermode.util.a.a(true);
        if (com.oppo.engineermode.util.a.b()) {
            u0.g("persist.vendor.meta.connecttype", "usb");
            SystemClock.sleep(200L);
            powerManager.reboot("reboot_eng");
        } else {
            v.e("RebootManager", "disable partion protect failed");
            Toast.makeText(this, "disable partion protect failed", 1).show();
            finish();
        }
    }
}
