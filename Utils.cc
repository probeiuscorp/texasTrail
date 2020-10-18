#include "Utils.h"

string Utils::formatAsCurrency(double dbl) {
    string stringed = std::to_string(round(dbl*100)/100);
    int periodIndex = -10;
    string cutString;
    for(int i=0;i<stringed.size();i++) {
        if(stringed.at(i) == '.') {
            periodIndex = i;
        }
        if(periodIndex+2 == i) {
            cutString = stringed.substr(0, periodIndex+3);
        }
    }
    stringed = string("$"+cutString);
    return stringed;
}

string Utils::numerateString(string chr, int count) {
    string str = "";
    for(int i=0;i<count;i++) {
        str += chr;
    }
    return str;
}