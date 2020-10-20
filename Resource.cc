#include "Resource.h"

Resource::Resource(string location){
    _location = "/home/caleb/.texastrail/"+location;
};
Resource::~Resource(){};

string Resource::location() const {
    return _location;
};