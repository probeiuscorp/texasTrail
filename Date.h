#ifndef TEXAS_TRAIL_DATE_H
#define TEXAS_TRAIL_DATE_H
#include <vector>
#include <string>
using std::vector;
using std::string;


class Date {
    public:
        Date(int hour, int day, int month, int year);
        virtual ~Date() {}

        void advance(int hours);

        string formattedTime() const;
        int hour() const { return _hour; }
        int day() const { return _day; }
        int month() const { return _month; }
        int year() const { return _hour; }

    private:
        int _hour;
        int _day;
        int _month;
        int _year;
        const vector<int> _monthLengths     = vector<int>({31,28,31,30,31,30,31,31,30,31,30,31});
        const vector<int> _monthLengthsLeap = vector<int>({31,29,31,30,31,30,31,31,30,31,30,31});

    private:
        int monthLength(int month) const;
};

#endif