package com.oppo.engineermode.util;

import android.content.Context;
import android.content.pm.ActivityInfo;
import android.os.IBinder;
import android.secrecy.ISecrecyService;

/* loaded from: classes.dex */
public abstract class k0 {

    /* renamed from: a, reason: collision with root package name */
    public static ISecrecyService f6948a;

    public static boolean a(Context context) {
        v.e("SecrecyServiceHelper", "doSecrecyEncryptAll");
        return "OK".equals(l.a(context, "secrecy", new String[]{"-config", "encrypt_all=true"}));
    }

    public static boolean b(int i9) {
        e();
        ISecrecyService iSecrecyService = f6948a;
        if (iSecrecyService != null) {
            try {
                return iSecrecyService.getSecrecyState(i9);
            } catch (Exception e9) {
                v.i("SecrecyServiceHelper", "getSecrecyState failed Exception", e9);
            }
        }
        return true;
    }

    public static boolean c(ActivityInfo activityInfo, String str, int i9, int i10) {
        e();
        ISecrecyService iSecrecyService = f6948a;
        if (iSecrecyService != null) {
            try {
                return iSecrecyService.isInEncryptedAppList(activityInfo, str, i9, i10);
            } catch (Exception e9) {
                v.i("SecrecyServiceHelper", "isInEncryptedAppList failed Exception", e9);
            }
        }
        return false;
    }

    public static boolean d() {
        e();
        ISecrecyService iSecrecyService = f6948a;
        if (iSecrecyService != null) {
            try {
                return iSecrecyService.isSecrecySupport();
            } catch (Exception e9) {
                v.i("SecrecyServiceHelper", "isSecrecySupported failed Exception", e9);
            }
        }
        return false;
    }

    public static void e() {
        if (f6948a == null) {
            try {
                IBinder a9 = b.a.a("secrecy");
                if (a9 != null) {
                    f6948a = ISecrecyService.Stub.asInterface(a9);
                }
            } catch (Exception e9) {
                v.i("SecrecyServiceHelper", "secrecyServiceInit failed Exception", e9);
            }
        }
    }
}
