#ifndef TEXAS_TRAIL_WINDOW_H
#define TEXAS_TRAIL_WINDOW_H
#include "render/Panel.h"
#include "Log.h"
#include <string>
using std::string;

class Window {
    public:
        Window(int width, int height);
        Window(int width, int height, string background);
        virtual ~Window(){};

        virtual void drawPanel(int x, int y, int width, int height);
        virtual void drawPanel(int x, int y, int width, int height, const vector<string>& contents);
        virtual void drawPanel(int x, int y, Panel& panel);
        virtual void drawPanel(Panel& panel);

        virtual void print();

    private:
        int _width;
        int _height;
        vector<string> _canvas;

};

#endif