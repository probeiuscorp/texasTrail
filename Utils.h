#ifndef TEXAS_TRAIL_UTILS_H
#define TEXAS_TRAIL_UTILS_H
#include <string>
#include <cctype>
#include <math.h>
using std::string;

class Utils {
    public:
        Utils(){};
        ~Utils(){};

        static string formatAsCurrency(double dbl);
        static string formatAsWeight(double dbl);
        static string numerateString(string str, int count);
        static string stringifyAndRound(double dbl, int round);
        static string toLower(string str);
        static string toUpper(string str);
};

#endif