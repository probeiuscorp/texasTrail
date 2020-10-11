#ifndef TEXAS_TRAIL_CITY_H
#define TEXAS_TRAIL_CITY_H
#include <string>

class City {
    public: 
        City();
        virtual ~City();

        virtual std::string name();

    private:
        std::string _name = "Indianapolis";
};

#endif