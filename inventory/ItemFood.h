#ifndef TEXAS_TRAIL_ITEM_FOOD_H
#define TEXAS_TRAIL_ITEM_FOOD_H
#include "inventory/Item.h"
#include <string>
using std::string;

class ItemFood : public Item {
    public:
        ItemFood(string name, double weight, double calories, double happiness, double health) : Item(name, weight), _calories(calories), _happiness(happiness), _health(health) {};
        virtual ~ItemFood() {};
        
        virtual double calories() const { return _calories; }
        virtual double happiness() const { return _happiness; }
        virtual double health() const { return _health; }
    
    private:
        double _calories;
        double _happiness;
        double _health;
};

#endif