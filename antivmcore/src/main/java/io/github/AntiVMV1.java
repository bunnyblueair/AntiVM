package io.github;

import android.content.Context;
import android.util.AndroidRuntimeException;
import android.util.Log;

import java.io.File;

/**
 * Created by bunny on 07/04/2017.
 */

public class AntiVMV1 extends IAntiVM {
    @Override
    public boolean antiVM(Context context) {
        String pkgPath=context.getPackageCodePath();
        File file=new File(pkgPath);
        Log.e("AntiVMV1",pkgPath);
        if (file.delete())
        {
           // throw new AndroidRuntimeException("found vm");
        }

        return false;
    }
}
