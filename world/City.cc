#include "City.h"

City::City(string name) : NodeFeature(), _name(name) {
    Shop* shop1 = new Shop("Ye Olde Shoppe");
    shop1->addStock(Shop::Stock(Stack(Items::AXLE), 3, 5.5));
    shop1->addStock(Shop::Stock(Stack(Items::EGG), 10, 1));
    shop1->addStock(Shop::Stock(Stack(Items::MUSKET), 1, 75));
    _shops.push_back(shop1);
}
City::~City() {}

std::string City::name() {
    return _name;
}