#ifndef TEXAS_TRAIL_ITEM_H
#define TEXAS_TRAIL_ITEM_H
#include <string>
using std::string;

class Item {
    public: 
        Item(string name, double weight);
        virtual ~Item();

        virtual string name() const { return _name; };
        virtual double weight() const { return _weight; }

    private:
        string _name;
        double _weight;

};

#endif