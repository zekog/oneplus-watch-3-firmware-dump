package com.oppo.engineermode.util;

/* loaded from: classes.dex */
public abstract class a {
    public static boolean a(boolean z8) {
        return q.r(z8);
    }

    public static boolean b() {
        return q.f();
    }

    public static boolean c() {
        if (!q.f()) {
            return true;
        }
        if (!q.r(false) || q.f()) {
            return false;
        }
        try {
            u0.f("vendor.oppo.quit.atm", "true");
            u0.f("vendor.oppo.engineer.usb.config", "adb");
        } catch (Exception e9) {
            v.e("ATMModeHelper", "set reset atm property caught exception : " + e9.getMessage());
        }
        b0.a(101);
        b0.a(1125);
        b0.e();
        return true;
    }
}
