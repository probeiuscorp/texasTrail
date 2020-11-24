#ifndef TEXAS_TRAIL_NODE_FEATURE_H
#define TEXAS_TRAIL_NODE_FEATURE_H
#include <string>
using std::string;

class NodeFeature {
    public:
        enum class EnumFeature {
            CITY
        };

    protected:
        NodeFeature(EnumFeature type);
        
    public:
        virtual ~NodeFeature();

        virtual bool isCity(NodeFeature& feature) { return false; }

        virtual EnumFeature type() { return _type; }  
        virtual string name() = 0;

    private:
        EnumFeature _type;
};

#endif