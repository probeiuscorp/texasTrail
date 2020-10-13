#include "Stack.h"

Stack::Stack(){};
Stack::Stack(Item item) : _item(item), _count(0) {};
Stack::Stack(Item item, int count) : _item(item), _count(count) {};
Stack::Stack(const Stack& source) {
    _item = source.item();
    _count = source.count();
}
Stack::~Stack(){};