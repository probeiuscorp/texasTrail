#ifndef TEXAS_TRAIL_UTILS_H
#define TEXAS_TRAIL_UTILS_H
#include "DialoguePrompt.h"
#include <string>
#include <vector>
#include <cctype>
#include <math.h>
using std::string;
using std::vector;

class Utils {
    public:
        using StringList = DialoguePrompt::StringList;

    public:
        Utils(){};
        ~Utils(){};

        static string formatAsCurrency(double dbl);
        static string formatAsWeight(double dbl);
        static string numerateString(string str, int count);
        static string stringifyAndRound(double dbl, int round);
        static string toLower(string str);
        static string toUpper(string str);
        static vector<string> split(string str, char delimeter);
        static bool chance(double chance);

        static StringList centerText(StringList stringList, int width, int height);
        static double min(double d1, double d2);
        static double max(double d1, double d2);
};

#endif