#include "City.h"

City::City() : NodeFeature() {
    Shop shop1("Ye Olde Shoppe");
    shop1.addStock(Shop::Stock(Stack(Items::AXLE), 3, 5.5));
    shop1.addStock(Shop::Stock(Stack(Items::EGG), 10, 1));
    shop1.addStock(Shop::Stock(Stack(Items::MUSKET), 1, 75));
    _shops.push_back(shop1);
}
City::~City() {}

std::string City::name() {
    return _name;
}