#include "Node.h"

Node::Node(NodeFeature* feature) :_feature(feature) {}
Node::~Node(){
    delete _feature;
}

void Node::addPath(Path* path) {
    _paths.push_back(path);
}

/*

Shop* shop;
delete shop;
shop = nullptr;

*/