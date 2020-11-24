#include "Node.h"

Node::Node(NodeFeature* feature, double x, double y) :_feature(feature), _x(x), _y(y) {}
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