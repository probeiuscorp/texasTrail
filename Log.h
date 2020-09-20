#ifndef LOG_TEXAS_TRAIL_H
#define LOG_TEXAS_TRAIL_H
#include <stdio.h>
#include <string>

class Log {
public: 
    Log();
    virtual ~Log();

    static void log(const char* output, ...);
};

#endif