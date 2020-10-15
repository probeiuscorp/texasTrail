#include "Stack.h"

Stack::Stack(const Item& item) : _item(item), _count(1) {};
Stack::Stack(const Item& item, int count) : _item(item), _count(count) {};
Stack::Stack(const Stack& source) : _item(source.item()) {
    _count = source.count();
}
Stack::~Stack(){};