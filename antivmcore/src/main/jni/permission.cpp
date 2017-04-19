//
// Created by BunnyBlue on 4/19/17.
//

#include "permission.h"
int checkPermission(char* path){
    return  0;
}
JNIEXPORT void JNICALL Java_io_github_Permission_permission(JNIEnv *env, jclass clazz,jstring jpath){

const char *nativeString = env->GetStringUTFChars( jpath, 0);
struct stat info;
char filename[1024];
struct passwd *pw = getpwuid(info.st_uid);
struct group  *gr = getgrgid(info.st_gid);

if(strcmp("pw->pw_name","system")!=0){
_exit(0);
}
env->ReleaseStringUTFChars(jpath, nativeString);
// If pw != 0, pw->pw_name contains the user name
// If gr != 0, gr->gr_name contains the group name

}
