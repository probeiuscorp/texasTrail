#include "Shop.h"

Shop::Shop() {

};
Shop::Shop(string name) : _name(name) {

}
Shop::Shop(string name, StockList stocks) :_name(name), _stocks(stocks) {

}
Shop::~Shop() {
    for(Stock* stock : _stocks) {
        delete stock;
    }
};

string Shop::name() const {
    return _name;
};

int Shop::stockSize() const {
    return _size;
}

Shop::Stock& Shop::stockAtIndex(int index) {
    if(index >= 0 && index < stockSize()) {
        return *(_stocks[index]);
    } else {
        printf("Index out of bounds. Index: %d, Size: %d", index, stockSize());
        abort();
    }
}

Stack& Shop::purchaseStock(int index, int amount) {
    if(index > 0 && index < stockSize()) {
        int count = _stocks[index]->getCount();
        Stack& stack = _stocks[index]->getStack();
        if(amount >= count) {
            removeStock(index);
        } else {
            _stocks[index]->setCount(count-amount);
        }
        return stack;
    } else { 
        printf("You tried to access a Stock out of bounds. Index: %d, Max: %d [Shop::purchaseStock]\n", index, stockSize());
        abort(); 
    }
}

void Shop::addStock(const Stock& stock) {
    _stocks.push_back(new Stock(stock));
    _size++;
}

void Shop::removeStock(int index) {
    if(index > 0 && index < stockSize()) {
        _stocks.erase(_stocks.begin()+index);
        _size--;
    }
}