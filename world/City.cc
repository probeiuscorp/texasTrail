#include "City.h"

City::City(string name) : NodeFeature(NodeFeature::EnumFeature::CITY), _name(name) {
    Shop* shop1 = new Shop("Ye Olde Shoppe");
    shop1->addStock(new Shop::Stock(new Stack(Items::AXLE, 3), 3, 5.5));
    shop1->addStock(new Shop::Stock(new Stack(Items::EGG, 2), 10, 1));
    shop1->addStock(new Shop::Stock(new Stack(Items::MUSKET), 1, 75));
    shop1->addStock(new Shop::Stock(new Stack(Items::MEDICINE, 4), 2, 3.25));
    _shops.push_back(shop1);
}
City::~City() {}

std::string City::name() {
    return string(_name+" (City)");
}