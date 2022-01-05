//
// Created by ven on 05/01/2022.
//

#ifndef VENWM_LOG_H
#define VENWM_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define LOG_TIME_FMT "%02d:%02d:%02d "
#define LOG_RESET "\e[0m\n"
#define LogFatal(FMT, ...) do {\
    LogError(FMT, ##__VA_ARGS__);\
    exit(1);                   \
} while (0)
#define LogError(FMT, ...) Log(stderr, "\e[0;31m" /* RED */ LOG_TIME_FMT FMT LOG_RESET, ##__VA_ARGS__)
#define LogWarn(FMT, ...) Log(stderr, "\e[0;33m" /* YELLOW */ LOG_TIME_FMT FMT LOG_RESET, ##__VA_ARGS__)
#define LogInfo(FMT, ...) Log(stdout, "\e[0;36m" /* CYAN */ LOG_TIME_FMT FMT LOG_RESET, ##__VA_ARGS__)
#ifdef DEBUG
    #define LogDebug(FMT, ...) Log(stdout, "\e[0;37m" /* WHITE */ LOG_TIME_FMT FMT LOG_RESET, ##__VA_ARGS__)
#else
    #define LogDebug(FMT, ...)
#endif

// Log to the fp. fmt must have LOG_TIME_FMT in it
void Log(FILE *fp, const char *fmt, ...);

#endif //VENWM_LOG_H
