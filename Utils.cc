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

vector<string> Utils::split(string str, char delimeter) {
    vector<string> slices = vector<string>();
    int start = 0;
    for(int i=0;i<str.length();i++) {
        if(str[i] == delimeter) {
            slices.push_back(str.substr(start, i));
            start = i + 1;
        }
    }
    slices.push_back(str.substr(start));
    return slices;
}

bool Utils::chance(double chance) {
    return (double)rand()/RAND_MAX < chance;
}

Utils::StringList Utils::centerText(StringList stringList, int width, int height) {
    StringList newList;
    for(int i=0;i<(height-stringList.size())/2;i++) {
        newList.push_back(numerateString(" ", width));
    }
    for(string str : stringList) {
        newList.push_back(string(numerateString(" ", (width-str.size())/2)+str+numerateString(" ", (int)(width-str.size()+0.5)/2)));
    }
    for(int i=0;i<(int)((height-stringList.size())/2.0+0.5);i++) {
        newList.push_back(numerateString(" ", width));
    }
    return newList;
}

double Utils::max(double d1, double d2) {
    return d1 > d2 ? d1 : d2;
}

double Utils::min(double d1, double d2) {
    return d1 < d2 ? d1 : d2;
}