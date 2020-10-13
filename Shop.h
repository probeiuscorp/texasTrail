#ifndef TEXAS_TRAIL_SHOP_H
#define TEXAS_TRAIL_SHOP_H
#include "TexasTrail.h"
#include "DialoguePrompt.h"
#include "inventory/Stack.h"
#include <string>
#include <list>
#include <vector>
using std::string;

class Shop {
    public:
        class Stock {
            public:
                Stock() {}
                Stock(Stack stack, int count, double price) : _stack(stack), _count(count), _price(price) {}
                ~Stock() {}

                Stack& getStack() { return _stack; }
                void setStack(Stack stack) { _stack = stack; }
                int getCount() { return _count; }
                void setCount(int count) { _count = count; }
                double getPrice() { return _price; }
                void setPrice(double price) { _price = price; }

            private:
                Stack _stack;
                int _count;
                double _price;
                
        };

    public:
        using StringList = std::vector<std::string>;
        using StockList = std::vector<Stock>;

    public:
        Shop();
        Shop(string name);
        Shop(string name, StockList stocks);
        virtual ~Shop();

        virtual string name() const;
        virtual int stockSize() const;
        virtual const Stock& stockAtIndex(int index) const;

        // Removes item(s) from stock and then returns it.
        virtual Stock& purchaseStock(int index, int amount);

    private:
        string _name;
        int _size;
        StockList _stocks;

};

#endif