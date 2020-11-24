#include "WorldGenerator.h"

WorldGenerator::WorldGenerator() {

}
WorldGenerator::~WorldGenerator() {

}

World* WorldGenerator::generateWorld() {
    World::TreeElementList pool;

    NodeFeature* startCity = new City("Austin");
    Node* startNode = new Node(startCity, 10.0, 10.0);

    NodeFeature* endCity = new City("Dallas");
    Node* endNode = new Node(endCity, 15.0, 15.0);

    Path* connector = new Path(*startNode, *endNode, Biomes::FOREST);

    pool.push_back(endNode);
    pool.push_back(startNode);
    pool.push_back(connector);

    return new World(startNode);
}