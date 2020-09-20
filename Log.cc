#include "Log.h"
#include <stdarg.h>

Log::Log(){};
Log::~Log(){};

void Log::log(const char* output, ...) {
    va_list args;
    va_start(args, output);
    vprintf(output, args);
    va_end(args);
};