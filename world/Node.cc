#include "Node.h"

Node::Node(NodeFeature* feature) :_feature(feature) {}
Node::~Node(){
    delete _feature;
}

/*

Shop* shop;
delete shop;
shop = nullptr;

*/