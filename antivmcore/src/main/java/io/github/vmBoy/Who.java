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

package io.github.vmBoy;

/**
 * Created by bunnyblue on 4/20/17.
 */

public class Who {
    static {
        System.loadLibrary("antivm");
    }

    /**
     * TODO need impl
     * check map file
     *
     */
    public static native void map();

    /**
     * try delete apk file,if run in vm,should be deleted
     *
     * @param path
     * @return
     */
    public static native int unlink(String path);

    /**
     * TODO  need inpl
     * check apk file permission
     *
     * @param path
     */
    public native static void permission(String path);
}
