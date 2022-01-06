//
// Created by ven on 05/01/2022.
//

#include "log.h"
#include <string.h>

void Log(FILE *fp, const char *fmt, ...) {
    char* newFmt = malloc((strlen(fmt) + 12) * sizeof(char));
    time_t secs = time(0);
    struct tm *local = localtime(&secs);

    sprintf(newFmt, "%02d:%02d:%02d %s", local->tm_hour, local->tm_min, local->tm_sec, fmt);

    va_list args;
    va_start(args, fmt);
    vfprintf(fp, newFmt, args);
    va_end(args);

    free(newFmt);
}