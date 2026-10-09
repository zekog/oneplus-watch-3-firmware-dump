package com.oppo.engineermode.util;

import android.os.IHwBinder;
import com.oppo.engineermode.EngineerModeApplication;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.ArrayList;
import java.util.List;
import java.util.function.BiConsumer;

/* loaded from: classes.dex */
public abstract class q {

    /* renamed from: a, reason: collision with root package name */
    public static Object f6968a;

    /* renamed from: b, reason: collision with root package name */
    public static c f6969b = new c();

    /* loaded from: classes.dex */
    public static class b implements InvocationHandler {

        /* renamed from: a, reason: collision with root package name */
        public BiConsumer f6970a;

        public b(BiConsumer biConsumer) {
            this.f6970a = biConsumer;
        }

        @Override // java.lang.reflect.InvocationHandler
        public Object invoke(Object obj, Method method, Object[] objArr) {
            this.f6970a.accept((Integer) objArr[0], (String) objArr[1]);
            return null;
        }
    }

    /* loaded from: classes.dex */
    public static class c implements IHwBinder.DeathRecipient {
        public c() {
        }

        public void serviceDied(long j9) {
            v.a("EngineerHidlHelper", "engineer serviceDied! cookie = " + j9);
            Object unused = q.f6968a = null;
        }
    }

    /* loaded from: classes.dex */
    public static class d implements InvocationHandler {

        /* renamed from: a, reason: collision with root package name */
        public BiConsumer f6971a;

        public d(BiConsumer biConsumer) {
            this.f6971a = biConsumer;
        }

        @Override // java.lang.reflect.InvocationHandler
        public Object invoke(Object obj, Method method, Object[] objArr) {
            this.f6971a.accept(objArr[0], objArr[1]);
            return null;
        }
    }

    /* loaded from: classes.dex */
    public static class e implements InvocationHandler {

        /* renamed from: a, reason: collision with root package name */
        public BiConsumer f6972a;

        public e(BiConsumer biConsumer) {
            this.f6972a = biConsumer;
        }

        @Override // java.lang.reflect.InvocationHandler
        public Object invoke(Object obj, Method method, Object[] objArr) {
            this.f6972a.accept((Integer) objArr[0], (String) objArr[1]);
            return null;
        }
    }

    public static int A(String str, int i9, boolean z8, int i10, byte[] bArr) {
        j();
        try {
            if (f6968a == null) {
                return -1;
            }
            Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
            Class cls2 = Integer.TYPE;
            return ((Integer) cls.getMethod("writeData", String.class, cls2, Boolean.TYPE, cls2, ArrayList.class).invoke(f6968a, str, Integer.valueOf(i9), Boolean.valueOf(z8), Integer.valueOf(i10), x(bArr))).intValue();
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return -1;
        }
    }

    public static boolean b(String str) {
        v.a("EngineerHidlHelper", "queryEngineerPersistData category: " + str);
        return r0.a(EngineerModeApplication.g(), str);
    }

    public static void c(BiConsumer biConsumer) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class<?> cls2 = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer$exportAttkKeyPairCallback");
                Object newProxyInstance = Proxy.newProxyInstance(cls2.getClassLoader(), new Class[]{cls2}, new b(biConsumer));
                Method method = cls.getMethod("exportAttkKeyPair", cls2);
                method.setAccessible(true);
                method.invoke(f6968a, newProxyInstance);
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "exportAttkKeyPair exception caught " + e9.getMessage());
        }
    }

    public static int d(int i9) {
        j();
        try {
            if (f6968a != null) {
                return ((Integer) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("generateAttkKeyPair", Integer.TYPE).invoke(f6968a, Integer.valueOf(i9))).intValue();
            }
            return 0;
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return 0;
        }
    }

    public static void e(BiConsumer biConsumer) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class<?> cls2 = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer$getDeviceIdCallback");
                Object newProxyInstance = Proxy.newProxyInstance(cls2.getClassLoader(), new Class[]{cls2}, new b(biConsumer));
                Method method = cls.getMethod("getDeviceId", cls2);
                method.setAccessible(true);
                method.invoke(f6968a, newProxyInstance);
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "getDeviceId exception caught " + e9.getMessage());
        }
    }

    public static boolean f() {
        j();
        try {
            if (f6968a != null) {
                return ((Boolean) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("getPartionWriteProtectState", null).invoke(f6968a, null)).booleanValue();
            }
            return false;
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return false;
        }
    }

    public static byte[] g() {
        j();
        try {
            if (f6968a != null) {
                return y((ArrayList) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("getProductLineTestResult", null).invoke(f6968a, null));
            }
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
        }
        return null;
    }

    public static void h(String str, BiConsumer biConsumer) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class<?> cls2 = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer$getVibratorCalibrateResultCallback");
                Object newProxyInstance = Proxy.newProxyInstance(cls2.getClassLoader(), new Class[]{cls2}, new e(biConsumer));
                Method method = cls.getMethod("getVibratorCalibrateResult", String.class, cls2);
                method.setAccessible(true);
                method.invoke(f6968a, str, newProxyInstance);
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "getVibratorF0 exception caught " + e9.getMessage());
        }
    }

    public static void i(BiConsumer biConsumer) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class<?> cls2 = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer$getImpedanceCallback");
                Object newProxyInstance = Proxy.newProxyInstance(cls2.getClassLoader(), new Class[]{cls2}, new e(biConsumer));
                Method method = cls.getMethod("getImpedance", cls2);
                method.setAccessible(true);
                method.invoke(f6968a, newProxyInstance);
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "getVibratorImpedance exception caught " + e9.getMessage());
        }
    }

    public static void j() {
        if (f6968a == null) {
            try {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Object invoke = cls.getMethod("getService", null).invoke(cls, null);
                f6968a = invoke;
                if (invoke != null) {
                    cls.getMethod("linkToDeath", IHwBinder.DeathRecipient.class, Long.TYPE).invoke(f6968a, f6969b, 0);
                }
            } catch (Exception e9) {
                v.e("EngineerHidlHelper", e9.getMessage());
                f6968a = null;
            }
        }
    }

    public static String k(String str, String str2) {
        v.a("EngineerHidlHelper", "queryEngineerPersistData category: " + str + " itemName " + str2);
        return (String) r0.d(EngineerModeApplication.g(), str, str2, "");
    }

    public static int l(String str) {
        j();
        try {
            if (f6968a != null) {
                return ((Integer) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("queryMountPointMounted", String.class).invoke(f6968a, str)).intValue();
            }
            return -1;
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return -1;
        }
    }

    public static void m(String str, int i9, int i10, BiConsumer biConsumer) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class<?> cls2 = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer$readDataCallback");
                Object newProxyInstance = Proxy.newProxyInstance(cls2.getClassLoader(), new Class[]{cls2}, new d(biConsumer));
                Class cls3 = Integer.TYPE;
                Method method = cls.getMethod("readData", String.class, cls3, cls3, cls2);
                method.setAccessible(true);
                method.invoke(f6968a, str, Integer.valueOf(i9), Integer.valueOf(i10), newProxyInstance);
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "readData exception caught " + e9.getMessage());
        }
    }

    public static byte[] n(int i9) {
        j();
        try {
            if (f6968a != null) {
                return y((ArrayList) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("readEngineerData", Integer.TYPE).invoke(f6968a, Integer.valueOf(i9)));
            }
            return null;
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return null;
        }
    }

    public static boolean o() {
        j();
        try {
            if (f6968a != null) {
                return ((Boolean) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("resetProductLineTestResult", null).invoke(f6968a, null)).booleanValue();
            }
            return false;
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return false;
        }
    }

    public static boolean p(int i9, byte[] bArr, int i10) {
        j();
        try {
            if (f6968a == null) {
                return false;
            }
            Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
            Class cls2 = Integer.TYPE;
            return ((Boolean) cls.getMethod("saveEngineerData", cls2, ArrayList.class, cls2).invoke(f6968a, Integer.valueOf(i9), x(bArr), Integer.valueOf(i10))).booleanValue();
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return false;
        }
    }

    public static boolean q(String str, String str2, String str3) {
        if (str2 == null || str2.isEmpty() || str3 == null || str3.length() <= 0) {
            v.c("EngineerHidlHelper", "saveAgingReportItem invalid parameter");
            return false;
        }
        r0.f(EngineerModeApplication.g(), str, str2, str3);
        return true;
    }

    public static boolean r(boolean z8) {
        j();
        try {
            if (f6968a != null) {
                return ((Boolean) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("setPartionWriteProtectState", Boolean.TYPE).invoke(f6968a, Boolean.valueOf(z8))).booleanValue();
            }
            return false;
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return false;
        }
    }

    public static boolean s(int i9, int i10) {
        j();
        try {
            if (f6968a == null) {
                return false;
            }
            Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
            Class cls2 = Integer.TYPE;
            return ((Boolean) cls.getMethod("setProductLineTestResult", cls2, cls2).invoke(f6968a, Integer.valueOf(i9), Integer.valueOf(i10))).booleanValue();
        } catch (Exception e9) {
            v.e("EngineerHidlHelper", e9.getMessage());
            return false;
        }
    }

    public static boolean t(String str, String str2) {
        j();
        try {
            if (f6968a != null) {
                return ((Boolean) Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("setProperties", String.class, String.class).invoke(f6968a, str, str2)).booleanValue();
            }
            return false;
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "setProperties exception caught " + e9.getMessage());
            return false;
        }
    }

    public static void u(String str, int i9) {
        j();
        try {
            if (f6968a != null) {
                Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("setVibratorCalibrateData", String.class, Integer.TYPE).invoke(f6968a, str, Integer.valueOf(i9));
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "setVibratorCalibrateData exception caught " + e9.getMessage());
        }
    }

    public static void v(int i9, int i10) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class cls2 = Integer.TYPE;
                cls.getMethod("startAgeVibrate", cls2, cls2).invoke(f6968a, Integer.valueOf(i9), Integer.valueOf(i10));
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "startAgeVibrate exception caught " + e9.getMessage());
        }
    }

    public static void w(int i9, int i10, int i11) {
        j();
        try {
            if (f6968a != null) {
                Class<?> cls = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer");
                Class cls2 = Integer.TYPE;
                cls.getMethod("startVibrate", cls2, cls2, cls2).invoke(f6968a, Integer.valueOf(i9), Integer.valueOf(i10), Integer.valueOf(i11));
            }
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "startVibrate exception caught " + e9.getMessage());
        }
    }

    public static ArrayList x(byte[] bArr) {
        if (bArr == null || bArr.length == 0) {
            return null;
        }
        ArrayList arrayList = new ArrayList();
        for (int i9 = 0; i9 < bArr.length; i9++) {
            arrayList.add(i9, Byte.valueOf(bArr[i9]));
        }
        return arrayList;
    }

    public static byte[] y(List list) {
        if (list == null || list.size() == 0) {
            return null;
        }
        byte[] bArr = new byte[list.size()];
        for (int i9 = 0; i9 < list.size(); i9++) {
            bArr[i9] = ((Byte) list.get(i9)).byteValue();
        }
        return bArr;
    }

    public static int z() {
        Object invoke;
        j();
        try {
            if (f6968a == null || (invoke = Class.forName("vendor.oplus.hardware.engineer.V1_0.IEngineer").getMethod("verifyAttkKeyPair", null).invoke(f6968a, null)) == null) {
                return -1;
            }
            return ((Integer) invoke).intValue();
        } catch (Exception e9) {
            v.c("EngineerHidlHelper", "verifyAttkKeyPair exception caught " + e9.getMessage());
            return -1;
        }
    }
}
