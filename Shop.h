#ifndef TEXAS_TRAIL_SHOP_H
#define TEXAS_TRAIL_SHOP_H
#include "DialoguePrompt.h"
#include "inventory/Stack.h"
#include "inventory/Inventory.h"
#include "Party.h"
#include <string>
#include <list>
#include <vector>
using std::string;

class Shop {
    public:
        enum class EnumShopRet {
            SUCCESS,
            NOT_ENOUGH_SPACE,
            NOT_ENOUGH_MONEY
        };

    public:
        class Stock {
            public:
                Stock(Stack* stack, int count, double price) : _stack(stack), _count(count), _price(price) {}
                ~Stock() { delete _stack; }

                Stack& getStack() { return *(_stack); }
                int getCount() const { return _count; }
                void setCount(int count) { _count = count; }
                double getPrice() const { return _price; }
                void setPrice(double price) { _price = price; }

            private:
                Stack* _stack;
                int _count;
                double _price;
                
        };

    public:
        using StringList = std::vector<std::string>;
        using StockList = std::vector<Stock*>;

    public:
        Shop();
        Shop(string name);
        Shop(string name, StockList stocks);
        virtual ~Shop();

        virtual string name() const;
        virtual int stockSize() const;
        virtual Stock& stockAtIndex(int index);
        virtual void addStock(Stock* stock);
        virtual void removeStock(int index);

        EnumShopRet purchaseStock(int index, int amount, Party& party);

    private:
        string _name;
        int _size = 0;
        StockList _stocks;

};

#endif