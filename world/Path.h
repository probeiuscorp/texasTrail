#ifndef TEXAS_TRAIL_PATH_H
#define TEXAS_TRAIL_PATH_H
#include "Node.h"
#include "Biome.h"

class Path : public TreeElement {
    public:
        Path(Node& nodeFrom, Node& nodeTo, int distance, const Biome& biome);
        virtual ~Path();
        
        const Biome& biome() { return _biome; }
        int distance() { return _distance; }

    private:
        Node& _nodeFrom;
        Node& _nodeTo;
        int _distance;
        const Biome& _biome;
};

#endif