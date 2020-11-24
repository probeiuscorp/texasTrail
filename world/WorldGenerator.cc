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

    NodeFeature* goalFeature = new EndNode("Lubbock");
    Node* goalNode = new Node(goalFeature, 40.0, 35.0);

    Path* connector = new Path(*startNode, *endNode, Biomes::FOREST);
    Path* toEnd = new Path(*endNode, *goalNode, Biomes::MOUNTAINS);

    pool.push_back(endNode);
    pool.push_back(startNode);
    pool.push_back(goalNode);
    pool.push_back(connector);
    pool.push_back(toEnd);

    return new World(startNode);
}