package com.gundoom.ndk;

import android.util.Log;

/**
 * Created by lroyd on 2018/7/23.
 */

public class Template {
    private native static void classInitNative();
    public native int devEnable();
    public native int devDisable();
    public native int devContral();

    public void onEventCallbck(int cmd, String msg){
        Log.d("template","cmd = "+cmd + " msg = "+msg);
    }

    public Template(){
        classInitNative();
    }

    static {
        System.loadLibrary("native_template");
    }
}
