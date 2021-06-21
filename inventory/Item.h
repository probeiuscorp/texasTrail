#ifndef TEXAS_TRAIL_ITEM_H
#define TEXAS_TRAIL_ITEM_H
#include <string>
using std::string;

class Person;
class Wagon;
class Item {
    public: 
        Item(string name, double weight);
        virtual ~Item();

        virtual string name() const { return _name; };
        virtual double weight() const { return _weight; }

        virtual bool canBeUsedOnPerson() const { return false; }
        virtual bool canBeUsedOnWagon() const  { return false; }
        virtual bool usableOnPerson(Person* person) const { return false; }
        virtual bool usableOnWagon(Wagon* wagon) const { return false; }
        virtual string useOnPerson(Person* person) const { return ""; }
        virtual string useOnWagon(Wagon* wagon) const { return ""; }

    private:
        string _name;
        double _weight;

};

#endif