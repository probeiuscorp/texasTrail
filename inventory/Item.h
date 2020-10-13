#ifndef TEXAS_TRAIL_ITEM_H
#define TEXAS_TRAIL_ITEM_H
#include <string>
using std::string;

class Item {
    public: 
        Item();
        virtual ~Item();

        string name() const { return _name; };

    private:
        string _name;

};

#endif