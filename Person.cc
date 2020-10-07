#include "Person.h"

Person::Person() {};
Person::Person(string name) : _name(name) {};
Person::~Person() {};

void Person::setName(string name) {
    _name = name;
}
std::string Person::getName() const {
    return _name;
}