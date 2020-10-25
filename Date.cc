#include "Date.h"

Date::Date(int hour, int day, int month, int year) :_hour(hour), _day(day), _month(month), _year(year) {}

string Date::formattedTime() const {
    string str = "";
    str += std::to_string(_month);
    str += "/";
    str += std::to_string(_day);
    str += "/";
    str += std::to_string(_year);
    str += " ";
    str += std::to_string(_hour % 12);
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
        _day++;
        if(_day > monthLength(_month)) {
            _month++;
            if(_month > 12) {
                _year++;
            }
        }
    }
    _hour %= 24;
    _day %= monthLength(_month);
    _month %= 12;
}

int Date::monthLength(int month) const {
    if(_year % 4 == 0) {
        return _monthLengthsLeap[month];
    } else {
        return _monthLengths[month];
    }
}