#include "Date.h"

Date::Date(int hour, int day, int month, int year) :_hour(hour), _day(day), _month(month), _year(year) {}

string Date::formattedTime() const {
    string str = "";
    str += pad(std::to_string(_month), 2, "0");
    str += "/";
    str += pad(std::to_string(_day), 2, "0");
    str += "/";
    str += std::to_string(_year);
    str += " ";
    str += pad(std::to_string((_hour-1) % 12 + 1), 2, "0");
    str += ":00 ";
    if(_hour < 12 || _hour == 24) {
        str += "AM";
    } else {
        str += "PM";
    }
    return str;
}

void Date::advance(int hours) {
    _hour += hours;
    if(_hour > 24) {
        _hour %= 24;
        _day++;
        if(_day > monthLength(_month)) {
            _day = 1;
            _month++;
            if(_month > 12) {
                _month = 1;
                _year++;
            }
        }
    }
}

int Date::monthLength(int month) const {
    if(_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0)) {
        return _monthLengthsLeap[month-1];
    } else {
        return _monthLengths[month-1];
    }
}

void Date::setTime(int hour, int day, int month, int year) {
    _hour = hour;
    _day = day;
    _month = month;
    _year = year;
}

string Date::pad(string str, int num, string with) const {
    for(int i=0;i<num-str.size();i++) {
        str = with + str;
    }
    return str;
}

bool Date::isDay() const {
    return _hour >= 6 && _hour <= 22;    
}

bool Date::isNight() const {
    return !isDay();
}