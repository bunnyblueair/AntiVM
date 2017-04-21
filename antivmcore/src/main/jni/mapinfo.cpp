//
// Created by BunnyBlue on 4/14/17.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapinfo.h"
#include "antivm.h"

// /data/app/bunnyblue.io.antivm-1/oat/x86/base.odex
char *filterPackage(char *string) {
    int all_len = strlen(string);
    char *s = strchr(string, '/data/app/');
    // LOGD("filterPackage input %s",string);
    if (strcmp(s, string) != 0) {
        return NULL;
    }
    int head_len = 10;
    // LOGE("filterPackage 1  %s ", s);
    s = strchr(s, '/');

    //  LOGE("filterPackage 2 %s ", s);
    s = strchr(s, '/');
    // LOGE("filterPackage 3 %s ", s);
    char *end = strchr(string, '-');
    // LOGE("filterPackage 4 %s ", end);
    int end_len = strlen(end);
    int pkglen = all_len - end_len - head_len;
    int n = 32;
    //char *src = "some really really long, more than 32 chars, string."
    //char dst[128] = {'\0'};
    char *dst = (char *) calloc(128, sizeof(char));

    strncpy(dst, string + 10, pkglen);
//    if (strcmp(dst, "bunnyblue.io.antivm") != 0) {
//        LOGE("fault pkg %s ", dst);
//        _exit(0);
//    }
    //dst[n] = '\0';
    return dst;

    // return NULL;
}

int isOdex(char *string) {
    char *end = strrchr(string, '.');

    if (end != NULL) {

        //  LOGE("test %s  == %s",end,".odex");
        return (strcmp(end, ".odex"));
    }

    return (-1);
}

static mapinfo *parse_maps_line(char *line) {
    mapinfo *mi;
    int len = strlen(line);

    if (len < 1)
        return 0;
    line[--len] = 0;

    if (len < 50)
        return 0;

    if (isOdex(line) != 0) {
        return 0;
    }

    //LOGE("line[20] %c %c %c %c",line[18],line[19],line[20],line[21]);
/*	if (line[18] != 'r'||line[19] != '-'||line[20] != '-'||line[21] != 's')
		return 0;*/

    mi = (mapinfo *) malloc(sizeof(mapinfo) + (len - 47));
    if (mi == 0)
        return 0;
    mi->pkgRef = 1;
    mi->start = strtoul(line, 0, 16);
    mi->end = strtoul(line + 9, 0, 16);
    /* To be filled in parse_elf_info if the mapped section starts with
     * elf_header
     */
    mi->next = 0;
    strcpy(mi->name, line + 49);
    fixPath(mi->name);
    return mi;
}

int updatePkg(mapinfo *milist, mapinfo *mi) {
    mapinfo *ptr = milist;
    while (ptr != NULL) {
        if (strcmp(mi->name, ptr->name) == 0) {
            ptr->pkgRef = ptr->pkgRef + mi->pkgRef;
            return 0;
        }
        ptr = ptr->next;
    }
    return 1;
}
mapinfo *init_mapinfo(int pid) {
    struct mapinfo *milist = NULL;

    char data[1024];
    sprintf(data, "/proc/%d/maps", pid);
    FILE *fp = fopen(data, "r");
    if (fp) {
        while (fgets(data, sizeof(data), fp)) {
            mapinfo *mi = parse_maps_line(data);

            if (mi) {
                char *fixed = filterPackage(mi->name);
                strcpy(mi->name, fixed);
                free(fixed);
                if (updatePkg(milist, mi) == 0) {

                    continue;
                }
                mi->next = milist;
                milist = mi;
            }
        }
        fclose(fp);
    }

    return milist;
}

void deinit_mapinfo(mapinfo *mi) {
    mapinfo *del;
    while (mi) {
        del = mi;
        mi = mi->next;
        free(del);
    }
}

/* Map a pc address to the name of the containing ELF file */
const char *map_to_name(mapinfo *mi, unsigned pc, const char *def) {
    while (mi) {
        if ((pc >= mi->start) && (pc < mi->end)) {
            return mi->name;
        }
        mi = mi->next;
    }
    return def;
}

/* Find the containing map info for the pc */
const mapinfo *pc_to_mapinfo(mapinfo *mi, unsigned pc, unsigned *rel_pc) {
    *rel_pc = pc;
    while (mi) {
        if ((pc >= mi->start) && (pc < mi->end)) {
            // Only calculate the relative offset for shared libraries
            if (strstr(mi->name, ".so")) {
                *rel_pc -= mi->start;
            }
            return mi;
        }
        mi = mi->next;
    }
    return NULL;
}
