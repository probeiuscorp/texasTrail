#include "Shop.h"

Shop::Shop() {

};
Shop::Shop(string name) : _name(name) {

}
Shop::Shop(string name, StockList stocks) :_name(name), _stocks(stocks) {

}
Shop::~Shop() {};

string Shop::name() const {
    return _name;
};

int Shop::stockSize() const {
    return _size;
}

const Shop::Stock& Shop::stockAtIndex(int index) const {
    if(index > 0 && index < stockSize()) {
        return *(_stocks[index]);
    } else {
        return *(_stocks[0]);
    }
}

void Shop::purchaseStock(int index, int amount) {
    
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