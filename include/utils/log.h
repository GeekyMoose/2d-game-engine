#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <string.h>


#define LOG_SIZE 256

#define LOG(severity, format, ...)  printlog(stdout, __func__, __LINE__, severity, format, ##__VA_ARGS__)

#define LOG_WTF(format, ...)        LOG(static_cast<int>(LogSeverity::Wtf),     format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)      LOG(static_cast<int>(LogSeverity::Error),   format, ##__VA_ARGS__)
#define LOG_WARNING(format, ...)    LOG(static_cast<int>(LogSeverity::Warning), format, ##__VA_ARGS__)
#define LOG_CONFIG(format, ...)     LOG(static_cast<int>(LogSeverity::Config),  format, ##__VA_ARGS__)
#define LOG_TRACE(format, ...)      LOG(static_cast<int>(LogSeverity::Trace),   format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...)      LOG(static_cast<int>(LogSeverity::Debug),   format, ##__VA_ARGS__)


enum class LogSeverity : int {
    Wtf = 0,
    Error,
    Warning,
    Config,
    Trace,
    Debug
};


enum class LogConfig {
    LogSeverity = static_cast<int>(LogSeverity::Debug)
};


/** No check done for severity borns. */
inline const char* severityToChar(const int severity) {
    static const char* lookup[6] = {
        "WTF",
        "ERROR",
        "WARNING",
        "CONFIG",
        "TRACE",
        "DEBUG"
    };
    return lookup[severity];
}


inline void printlogList(FILE* os,
                  const char* func,
                  const int line,
                  const int severity,
                  const char *format,
                  va_list argsList) {
    char buffer[LOG_SIZE];
    memset(buffer, 0x0, LOG_SIZE);
    vsnprintf(buffer, LOG_SIZE, format, argsList);
    fprintf(os, "[%s]:[%s@%d]: %s\n", severityToChar(severity), func, line, buffer);
}

inline void printlog(FILE* os,
              const char* func,
              const int line,
              const int severity,
              const char *format,
              ...) {
    if(severity <= static_cast<int>(LogConfig::LogSeverity) && severity >= 0) {
        va_list argsList;
        va_start(argsList, format);
        printlogList(os, func, line, severity, format, argsList);
        va_end(argsList);
    }
}

