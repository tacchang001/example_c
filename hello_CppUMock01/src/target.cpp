#include "target.h"
#include <sys/statvfs.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

ulong get_disk_space(const char * const disk)
{
    ulong ds = -1;
    struct statvfs stat;

    if (statvfs(disk, &stat) == -1) {
        perror(disk);
    } else {
        ds = stat.f_bavail * stat.f_blocks;
    }

    return ds;
}