#ifndef TEXAS_TRAIL_CITY_H
#define TEXAS_TRAIL_CITY_H
#include "Shop.h"
#include "NodeFeature.h"
#include "inventory/Stack.h"
#include "inventory/Items.h" // TEMPORARY - REMOVE
#include "Party.h"
#include "UICity.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

class Shop;

class City : public NodeFeature {
    public:
        using ShopList = vector<Shop*>;

    public: 
        City(string name);
        virtual ~City();

        virtual bool isCity() { return true; }

        virtual string name();
        // virtual const ShopList& shops() { return _shops; }
        virtual int shopSize() { return _shops.size(); }
        virtual Shop& getShop(int index) { return *(_shops[index]); }

    private:
        string _name;
        ShopList _shops = ShopList();
};

#endif