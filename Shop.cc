#include "Shop.h"

Shop::Shop() {

};
Shop::Shop(string name) {

}
Shop::Shop(string name, StockList list) {

}
Shop::~Shop() {};

string Shop::name() const {
    return _name;
};

int Shop::stockSize() const {
    return _size;
}

const Shop::Stock& Shop::stockAtIndex(int index) const {
    return _stocks[index];
}

Shop::Stock& Shop::purchaseStock(int index, int amount) {
    return _stocks[index];
}