#include "City.h"

City::City() {}
City::~City() {}

std::string City::name() {
    return _name;
}

City::ShopList& City::shops() {
    return _shops;
}