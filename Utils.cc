#include "Utils.h"

string Utils::formatAsCurrency(double dbl) {
    string str = string("$"+stringifyAndRound(dbl, 2));
    return str;
}

string Utils::formatAsWeight(double dbl) {
    string str = string(stringifyAndRound(dbl, 2)+" lbs");
    return str;
}

string Utils::numerateString(string chr, int count) {
    string str = "";
    for(int i=0;i<count;i++) {
        str += chr;
    }
    return str;
}

string Utils::stringifyAndRound(double dbl, int rnd) {
    string stringed = std::to_string(round(dbl*100)/100);
    int periodIndex = -10;
    string cutString;
    for(int i=0;i<stringed.size();i++) {
        if(stringed.at(i) == '.') {
            periodIndex = i;
        }
        if(periodIndex+rnd == i) {
            cutString = stringed.substr(0, periodIndex+rnd+1);
        }
    }
    return cutString;
}

string Utils::toLower(string str) {
    string str2 = "";
    auto it = str.begin();
    while(it != str.end()) {
        str2 += std::tolower(*it);
        it++;
    }
    return str2;
}

string Utils::toUpper(string str) {
    string str2 = "";
    auto it = str.begin();
    while(it != str.end()) {
        str2 += std::toupper(*it);
        it++;
    }
    return str2;
}