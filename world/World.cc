#include "World.h"

World::World(Node* firstNode) : _firstNode(firstNode) {

}

World::~World() {
    delete _firstNode;
}

void World::deleteTree() {
    for(TreeElement* e : _treeElementPool) delete e;
}

Node& World::startingNode() {
    return *_firstNode;
}