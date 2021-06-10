#ifndef TEXAS_TRAIL_WAGON_H
#define TEXAS_TRAIL_WAGON_H
#include <vector>
#include <string>
using std::vector;
using std::string;

class ICargo;
class Wagon {
    public:
        using CargoList = vector<ICargo*>;

    public:
        Wagon(double capacity);
        virtual ~Wagon();

        // Returns false if adding the item failed, i.e. there wasn't enough space
        virtual bool add(ICargo* item);
        virtual const CargoList content() const;
        virtual void remove(int index);
        virtual double capacity() const { return _capacity; };
        virtual double weight() const { return _weight; }
    
    private:
        CargoList _content;
        double _capacity;
        double _weight = 0;
};

#endif