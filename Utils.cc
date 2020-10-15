#include "Utils.h"

string Utils::formatAsCurrency(double dbl) {
    string stringed = std::to_string(round(dbl*100)/100);
    // stringed = "55.5000" 
    // periodIdex = 2
    // size = 7
    // .substr(0, 5)
    // .substr(0, size - 3 - periodIndex)
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