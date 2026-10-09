package com.oppo.engineermode.util;

/* loaded from: classes.dex */
public abstract class b0 {
    public static int a(int i9) {
        try {
            Object invoke = Class.forName("android.os.OplusManager").getMethod("cleanItem", Integer.TYPE).invoke(null, Integer.valueOf(i9));
            if (invoke != null) {
                return ((Integer) invoke).intValue();
            }
            return -1;
        } catch (Exception e9) {
            v.e("OplusManagerHelper", "OplusManager cleanItem" + e9.getMessage());
            return -1;
        }
    }

    public static int b(int i9) {
        try {
            Object invoke = Class.forName("android.os.OplusManager").getMethod("readCriticalData", Integer.TYPE).invoke(null, Integer.valueOf(i9));
            if (invoke != null) {
                return ((Integer) invoke).intValue();
            }
            return -1;
        } catch (Exception e9) {
            v.e("OplusManagerHelper", "OplusManager ClassNotFoundException" + e9.getMessage());
            return -1;
        }
    }

    public static String c(int i9, int i10) {
        try {
            Class<?> cls = Class.forName("android.os.OplusManager");
            Class cls2 = Integer.TYPE;
            return (String) cls.getMethod("readCriticalData", cls2, cls2).invoke(null, Integer.valueOf(i9), Integer.valueOf(i10));
        } catch (Exception e9) {
            v.e("OplusManagerHelper", "OplusManager readCriticalData" + e9.getMessage());
            return null;
        }
    }

    public static String d(int i9, int i10) {
        try {
            Class<?> cls = Class.forName("android.os.OplusManager");
            Class cls2 = Integer.TYPE;
            return (String) cls.getMethod("readRawPartition", cls2, cls2).invoke(null, Integer.valueOf(i9), Integer.valueOf(i10));
        } catch (Exception e9) {
            v.e("OplusManagerHelper", "OplusManager readRawPartition" + e9.getMessage());
            return null;
        }
    }

    public static int e() {
        try {
            Object invoke = Class.forName("android.os.OplusManager").getMethod("syncCacheToEmmc", null).invoke(null, null);
            if (invoke != null) {
                return ((Integer) invoke).intValue();
            }
            return -1;
        } catch (Exception e9) {
            v.e("OplusManagerHelper", "OplusManager syncCacheToEmmc" + e9.getMessage());
            return -1;
        }
    }

    public static int f(int i9, String str) {
        try {
            Object invoke = Class.forName("android.os.OplusManager").getMethod("writeCriticalData", Integer.TYPE, String.class).invoke(null, Integer.valueOf(i9), str);
            if (invoke != null) {
                return ((Integer) invoke).intValue();
            }
            return -1;
        } catch (Exception e9) {
            v.e("OplusManagerHelper", "OplusManager writeCriticalData" + e9.getMessage());
            return -1;
        }
    }
}
