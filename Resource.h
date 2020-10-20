#ifndef TEXAS_TRAIL_RESOURCE_H
#define TEXAS_TRAIL_RESOURCE_H
#include <string>
using std::string;

class Resource {
    public:
        Resource(string location);
        virtual ~Resource();

        string location() const;

    private:
        string _location;
};

#endif