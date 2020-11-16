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
        printf("Index out of bounds. Index: %d, Size: %d [Shop::stockAtIndex()]\n", index, stockSize());
        abort();
    }
}

Inventory::AddRet Shop::purchaseStock(int index, int amount, Party& party) {
    if(index >= 0 && index < stockSize()) {
        // amount - requested purchase size :: count - actual size of stock
        int count = _stocks[index]->getCount();
        Stack& stack = _stocks[index]->getStack();
        Inventory::AddRet ret;
        if(amount >= count) {
            ret = party.inventory().add(stack);
            if(ret == Inventory::AddRet::SUCCESS) {
                removeStock(index);
            }
        } else {
            ret = party.inventory().add(new Stack(stack.item(), amount));
            if(ret == Inventory::AddRet::SUCCESS) {
                _stocks[index]->setCount(count-amount);
            }
        }
        return ret;
    } else { 
        printf("You tried to access a Stock out of bounds. Index: %d, Size: %d [Shop::purchaseStock()]\n", index, stockSize());
        abort(); 
    }
}

void Shop::addStock(Stock* stock) {
    _stocks.push_back(stock);
    _size++;
}

void Shop::removeStock(int index) {
    if(index >= 0 && index < stockSize()) {
        _stocks.erase(_stocks.begin()+index);
        _size--;
    } else { 
        printf("You tried to access a Stock out of bounds. Index: %d, Size: %d [Shop::removeStock()]\n", index, stockSize());
        abort(); 
    }
} 