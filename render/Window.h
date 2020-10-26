#ifndef TEXAS_TRAIL_WINDOW_H
#define TEXAS_TRAIL_WINDOW_H
#include "render/Panel.h"
#include "Log.h"
#include "render/CanvasElement.h"
#include "Utils.h"
#include <string>
using std::string;

class Window {
    public:
        Window(int width, int height);
        Window(int width, int height, string background);
        virtual ~Window(){};

        virtual void drawPanel(int x, int y, int width, int height);
        virtual void drawPanel(int x, int y, int width, int height, const vector<string>& contents);
        virtual void drawPanel(int x, int y, int width, int height, const vector<string>& contents, string header);
        virtual void drawPanel(int x, int y, Panel& panel);
        virtual void drawPanel(Panel& panel);
        virtual void drawString(int x, int y, string str);

        virtual void setColorXY(int x, int y, string color);
        virtual void setColorXY(int x, int y, int r, int g, int b);
        virtual void setColorRect(int x, int y, int width, int height, string color);
        virtual void setColorRect(int x, int y, int width, int height, int r, int g, int b);

        virtual void print(int offset);

    private:
        const int _width;
        const int _height;
        vector<vector<CanvasElement>> _canvas;
        vector<vector<CanvasElement>> _colors;

};

#endif