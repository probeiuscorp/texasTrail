#include "WorldGenerator.h"

WorldGenerator::WorldGenerator() {

}
WorldGenerator::~WorldGenerator() {

}

World* WorldGenerator::generateWorld() {
   World::TreeElementList pool;

   NodeFeature* startCity = new City("Austin");
   Node* startNode = new Node(startCity);

   NodeFeature* endCity = new City("Dallas");
   Node* endNode = new Node(endCity);

   Path* connector = new Path(*startNode, *endNode);

   pool.push_back(endNode);
   pool.push_back(startNode);
   pool.push_back(connector);

    return new World(startNode);
}