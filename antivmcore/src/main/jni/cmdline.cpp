//
// Created by BunnyBlue on 4/21/17.
//
#include "antivm.h"
#include "cmdline.h"

char *_default_package = NULL;

char *antivm_default_package() {
    if (_default_package != NULL) {
        return _default_package;
    }
    _default_package = (char *) calloc(256, sizeof(char));
    char data[1024] = {0};
    sprintf(data, "/proc/%d/cmdline", getpid());
    FILE *fp = fopen(data, "r");
    if (fp) {
        while (fgets(data, sizeof(data), fp)) {
            strcpy(_default_package, data);

        }
        fclose(fp);
    }


    return _default_package;
}

