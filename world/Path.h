#ifndef TEXAS_TRAIL_PATH_H
#define TEXAS_TRAIL_PATH_H
#include "Node.h"
#include "Biome.h"
#include <string>
using std::string;

class Path : public TreeElement {
    public:
        Path(Node& nodeFrom, Node& nodeTo, const Biome& biome);
        virtual ~Path();
        
        const Biome& biome() { return _biome; }
        double distance() { return _distance; }
        Node& nodeTo() { return _nodeTo; }
        Node& nodeFrom() { return _nodeFrom; }
        string name();

    private:
        Node& _nodeFrom;
        Node& _nodeTo;
        double _distance;
        const Biome& _biome;
};

#endif