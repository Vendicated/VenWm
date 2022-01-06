//
// Created by ven on 05/01/2022.
//

#ifndef VENWM_LOG_H
#define VENWM_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define LOG_RESET "\e[0m\n"
#define CHECK(condition, FMT, ...) if (!(condition)) { \
    LogFatal(FMT, ##__VA_ARGS__);          \
}
#define CHECK_EQ(x, y, FMT, ...) CHECK(x == y, FMT, ##__VA_ARGS__)
#define CHECK_NEQ(x, y, FMT, ...) CHECK(x != y, FMT, ##__VA_ARGS__)
#define CHECK_NOT_NULL(x, FMT, ...) CHECK_NEQ(x, NULL, FMT, ##__VA_ARGS__)
#define LogFatal(FMT, ...) do {\
    LogError(FMT, ##__VA_ARGS__);\
    exit(1);                   \
} while (0)
#define LogError(FMT, ...) Log(stderr, "\e[0;31m" /* RED */ FMT LOG_RESET, ##__VA_ARGS__)
#define LogWarn(FMT, ...) Log(stderr, "\e[0;33m" /* YELLOW */ FMT LOG_RESET, ##__VA_ARGS__)
#define LogInfo(FMT, ...) Log(stdout, "\e[0;36m" /* CYAN */ FMT LOG_RESET, ##__VA_ARGS__)
#ifdef DEBUG
#define LogDebug(FMT, ...) Log(stdout, "\e[0;37m" /* WHITE */ FMT LOG_RESET, ##__VA_ARGS__)
#else
#define LogDebug(FMT, ...)
#endif

// Log to the fp. fmt must have extra %s for date string in it
void Log(FILE *fp, const char *fmt, ...);

#endif //VENWM_LOG_H
