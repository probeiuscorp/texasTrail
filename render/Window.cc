#include "Window.h"

Window::Window(int width, int height) : Window(width, height, " ") {
    // Window(width, height, " ");
}
Window::Window(int width, int height, string background) : _width(width), _height(height) {
    for(int y=0;y<height;y++) {
        _canvas.push_back(vector<CanvasElement>());
        _colors.push_back(vector<CanvasElement>());
        for(int x=0;x<width;x++) {
            _canvas[y].push_back(CanvasElement(background));
            _colors[y].push_back(CanvasElement("\033[0m"));
        }
    }
}

void Window::drawPanel(Panel& panel) {
    drawPanel(panel.x(), panel.y(), panel.width(), panel.height(), panel.contents());
}

void Window::drawPanel(int x, int y, Panel& panel) {
    drawPanel(x, y, panel.width(), panel.height(), panel.contents());
}

void Window::drawPanel(int x, int y, int width, int height) {
    drawPanel(x, y, width, height, vector<string>());
}

void Window::drawPanel(int x, int y, int width, int height, const vector<string>& contents) {
    
    /*
    UNICODE GUIDE
    \u2500 = straight horizontal line
    \u2502 = straight vertical line
    \u256d = top left angle
    \u256e = top right angle
    \u2570 = bottom left angle
    \u256f = bottom right angle
    */

    // Whichever comes first, end of panel or end of window
    int minW = _width < width+x ? _width : width+x;
    int minH = _height < height+y ? _height : height+y;

    // Draw frame
    if(x < _width && y < _height) {
        for(int i=y;i<minH;i++) {
            for(int j=x;j<minW;j++) {
                // top of frame
                if(i==y) {
                    if(j==x) {
                        _canvas[i][j].setStr("\u256d");
                    } else if(j==minW-1) {
                        _canvas[i][j].setStr("\u256e");
                    } else {
                        _canvas[i][j].setStr("\u2500");
                    }
                }
                // bottom of frame
                else if(i==minH-1) {
                    if(j==x) {
                        _canvas[i][j].setStr("\u2570");
                    } else if(j==minW-1) {
                        _canvas[i][j].setStr("\u256f");
                    } else {
                        _canvas[i][j].setStr("\u2500");
                    }
                }
                else {
                    if(j==x) {
                        _canvas[i][j].setStr("\u2502");
                    } else if(j==minW-1) {
                        _canvas[i][j].setStr("\u2502");
                    } else {
                        _canvas[i][j].setStr(" ");
                        if(i-y-1 < contents.size()) {
                            if(j-x-1 < contents[i-y-1].size()) {
                                _canvas[i][j].setStr(contents[i-y-1].at(j-x-1));
                            }
                        }
                    }  
                }
            }
        }
    }
}

void Window::drawString(int x, int y, string str) {
    if(y < _height) {
        for(int i=0;i<str.size();i++) {
            if(x+i < _width) {
                _canvas[y][x+i].setStr(str.at(i));
            }
        }
    }
}

void Window::setColorXY(int x, int y, string color) {
    if(x>0 && y>0 && x< _width && y<_height) {
        _colors[y][x].setStr(color);
    }
}

void Window::setColorRect(int x, int y, int width, int height, string color) {
    for(int i=0;i<width;i++) {
        for(int j=0;j<height;j++) {
            setColorXY(x+i, y+j, color);
        }
    }
}

void Window::print(int offset) {
    for(int i=0;i<_height;i++) {
        Log::log("%s", Utils::numerateString(" ", offset).c_str());
        for(int j=0;j<_width;j++) {
            Log::log("%s%s", _colors[i][j].str().c_str(), _canvas[i][j].str().c_str());
        }
        Log::log("\n");
    }
}