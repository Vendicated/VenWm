//
// Created by ven on 05/01/2022.
//

#include "log.h"

void Log(FILE *fp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    time_t secs = time(0);
    struct tm *local = localtime(&secs);
    fprintf(fp, fmt, local->tm_hour, local->tm_min, local->tm_sec, args);
    va_end(args);
}