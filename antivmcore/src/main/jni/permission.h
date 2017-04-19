#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <jni.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <android/log.h>
#define TAG "AntiVM"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,  TAG, __VA_ARGS__)
#define LOGDT(T, ...) __android_log_print(ANDROID_LOG_DEBUG,  T, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,  TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#include <jni.h>
/* Header for class io_github_Permission */

#ifndef _Included_io_github_Permission
#define _Included_io_github_Permission
#ifdef __cplusplus
extern "C" {
#endif
int checkPermission(char* path);
/*
 * Class:     io_github_Permission
 * Method:    permission
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_io_github_Permission_permission
(JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif
