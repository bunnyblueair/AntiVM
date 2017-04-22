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

import io.github.antivm.IPackageFilter;

/**
 * Created by bunnyblue on 4/22/17.
 */

public class PackageFilter extends IPackageFilter {
    private static final String SYSTEM_PATH = "/system/";
    private static final String APP_PATH = "/data/app/";
    private static final String APP_MULTI_PATH = "/data/user/";

    @Override
    public String findPackageNoSystem(String pkgPath) {
        if (pkgPath.startsWith(SYSTEM_PATH)) {
            return null;
        } else if (pkgPath.startsWith(APP_PATH)) {
            pkgPath = pkgPath.replaceAll(APP_PATH, "");


            return pkgPath.substring(0, pkgPath.indexOf("-"));
        } else if (pkgPath.startsWith(APP_MULTI_PATH)) {
            pkgPath = pkgPath.replaceAll(APP_MULTI_PATH, "");

            pkgPath = pkgPath.substring(pkgPath.indexOf("/") + 1);
            pkgPath = pkgPath.substring(0, pkgPath.indexOf("/"));
            // pkgList.add(pkgPath);
            return pkgPath;

        }
        return null;
    }
}
