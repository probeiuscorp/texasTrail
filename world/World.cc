#include "World.h"

World::World() {

}

World::~World() {
    delete _firstNode;
}

void World::deleteTree() {
    for(TreeElement* e : _treeElementPool) delete e;
}