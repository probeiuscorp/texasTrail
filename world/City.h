#ifndef TEXAS_TRAIL_CITY_H
#define TEXAS_TRAIL_CITY_H
#include "Shop.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

class City {
    public:
        using ShopList = vector<Shop>;

    public: 
        City();
        virtual ~City();

        virtual string name();
        virtual ShopList& shops();

    private:
        string _name = "Indianapolis";
        ShopList _shops = ShopList({Shop(), Shop()});
};

#endif