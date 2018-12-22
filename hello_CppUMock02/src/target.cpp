#include "IBar.h"
#include <sys/statvfs.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h> // memory leak

ulong get_disk_space(const char * const disk)
{
    ulong ds = -1;
    struct statvfs stat;

    if (statvfs(disk, &stat) == -1) {
        perror(disk);
    } else {
        ds = stat.f_bavail * stat.f_blocks;

        char *leak = (char*)malloc(sizeof(char)*1); // memory leak
        *leak = 'a';
    }

    return ds;
}