/*
 * MIT License   Project AntiVM
 *
 * Copyright (c) 2017 Bunny Blue
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

package io.github.antivm.impl;

import android.content.Context;
import android.content.res.AssetManager;
import android.text.TextUtils;
import android.util.AndroidRuntimeException;
import android.util.Log;

import java.lang.reflect.Method;
import java.util.ArrayList;

import io.github.antivm.IResInjectDetect;

/**
 * Created by bunnyblue on 4/22/17.
 */

public class ResInJectDetectDefault extends IResInjectDetect {

    private static final String TAG = "ResInJectDetectDefault";
    PackageFilter packageFilter = new PackageFilter();

    @Override
    public void detectResource(Context context) {
        ArrayList<String> pkgList = getRunTimePackageNoSystem(context.getAssets());
        for (String pkg : pkgList) {
            if (!pkg.equals(context.getPackageName())) {
                throw new AndroidRuntimeException("bad pkg");
            }

        }
        // Log.e(TAG, "detectResource: " + pkgList+context.getPackageName());

    }

    private ArrayList<String> getRunTimePackageNoSystem(AssetManager manager) {
        ArrayList<String> pkgList = new ArrayList<String>();
        try {
            Method method = manager.getClass().getDeclaredMethod("getStringBlockCount");
            method.setAccessible(true);
            int assetsPathCount = (Integer) method.invoke(manager);
            for (int x = 0; x < assetsPathCount; x++) {
                // Cookies map to string blocks starting at 1
                String pkgPath = (String) manager.getClass().getMethod("getCookieName", int.class).invoke(manager, x + 1);
                Log.e(TAG, "getRunTimePackageNoSystem: " + pkgPath);
                String pkg = packageFilter.findPackageNoSystem(pkgPath);
                if (TextUtils.isEmpty(pkg)) {
                    continue;
                } else {
                    pkgList.add(pkg);
                    Log.e(TAG, "getRunTimePackageNoSystem: " + pkg);
                }

            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return pkgList;
    }
}

