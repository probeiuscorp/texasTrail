#include "Stack.h"

Stack::Stack(const Item& item) : _item(item), _count(1) {};
Stack::Stack(const Item& item, int count) : _item(item), _count(count) {};
Stack::Stack(const Stack& source) : _item(source.item()) {
    _count = source.count();
}
Stack::~Stack(){};

string Stack::formatted() const {
    string str = std::to_string(_count);
    str += "x ";
    str += _item.name();
    
    return str;
}