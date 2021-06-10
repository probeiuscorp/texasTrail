#include "Shop.h"
#include "Utils.h"

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

Shop::EnumShopRet Shop::purchaseStock(int index, int amount, Party& party) {
    if(index >= 0 && index < stockSize()) {
        // amount - requested purchase size :: count - actual size of stock
        int count = _stocks[index]->getCount();
        int actual = (amount > count ? count : amount);
        Stack& stack = _stocks[index]->getStack();

        if(_stocks[index]->getPrice()*actual > party.money()) {
            return EnumShopRet::NOT_ENOUGH_MONEY;
        }

        Shop::EnumShopRet ret;
        if(_stocks[index]->getPrice()*actual <= party.money()) {
            if(!(party.inventory().add(new Stack(stack.item(), actual)))) {
                _stocks[index]->setCount(count-amount);
                ret = EnumShopRet::SUCCESS;
            } else {
                ret = EnumShopRet::NOT_ENOUGH_SPACE;
            }
        }
        
        if(ret == EnumShopRet::SUCCESS) {
            party.modifyMoney(-_stocks[index]->getPrice()*actual);
        }

        if(_stocks[index]->getCount() <= 0) {
            removeStock(index);
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
        delete _stocks[index];
        _stocks.erase(_stocks.begin()+index);
        _size--;
    } else { 
        printf("You tried to access a Stock out of bounds. Index: %d, Size: %d [Shop::removeStock()]\n", index, stockSize());
        abort(); 
    }
} 