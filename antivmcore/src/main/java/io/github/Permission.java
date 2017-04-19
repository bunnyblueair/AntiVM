package io.github;

import android.util.Log;

/**
 * Created by bunnyblue on 4/19/17.
 */

public class Permission {static {
    try{System.loadLibrary("antivm");
        Log.e("Permission", "static initializer: ");
    }catch (UnsatisfiedLinkError e){
        e.printStackTrace();
    }
}
    public  native  static void permission(String path);
}
