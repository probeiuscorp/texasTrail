#ifndef TEXAS_TRAIL_PANEL_H
#define TEXAS_TRAIL_PANEL_H
#include <vector>
#include <string>
using std::vector;
using std::string;

class Panel {
    public:
        Panel(int width, int height);
        Panel(int x, int y, int width, int height);
        Panel(int width, int height, vector<string>& contents);
        Panel(int x, int y, int width, int height, vector<string>& contents);
        virtual ~Panel();

        int x() { return _x; }
        int y() { return _y; }
        int width() { return _width;}
        int height() { return _height; }
        vector<string>& contents() { return _contents; }

    private:
        int _x;
        int _y;
        int _width;
        int _height;
        vector<string>& _contents;
};

#endif