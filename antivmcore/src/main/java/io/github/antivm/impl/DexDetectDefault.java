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
import android.text.TextUtils;
import android.util.AndroidRuntimeException;
import android.util.Log;

import java.lang.reflect.Field;
import java.util.ArrayList;

import io.github.antivm.IDexDetect;

import static io.github.antivm.ReflectUtil.findField;

/**
 * Created by bunnyblue on 4/22/17.
 */

public class DexDetectDefault extends IDexDetect {


    private static final String TAG = "DexDetectDefault";
    PackageFilter packageFilter = new PackageFilter();

    @Override
    public void dexDetect(Context context) {
        ArrayList<String> dexs = findDexs(context);
        for (String dexpath : dexs) {
            if (!dexpath.equals(context.getPackageName())) {
                throw new AndroidRuntimeException("bad pkg");
            }

        }

    }

    private ArrayList<String> findDexs(Context context) {
        ArrayList<String> pkgList = new ArrayList<String>(32);
        ClassLoader loader = context.getClassLoader();
        Field pathListField = null;
        try {
            pathListField = findField(loader, "pathList");
            Object dexPathList = pathListField.get(loader);
            Field dexElementField = findField(dexPathList, "dexElements");
            Object[] dexElements = (Object[]) dexElementField.get(dexPathList);
            for (Object objElement :
                    dexElements) {
                Field dexFileField = findField(objElement, "dexFile");
                Object dexFile = dexFileField.get(objElement);
                String pkgName = packageFilter.findPackageNoSystem(dexFile.toString());
                if (!TextUtils.isEmpty(pkgName)) {
                    pkgList.add(pkgName);
                }
                Log.e(TAG, "dexDetect: ----" + dexFile.toString());


            }
            //Log.e(TAG, "dexDetect: " + dexElements);
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
        return pkgList;
    }
}
