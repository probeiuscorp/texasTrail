#include "Window.h"

Window::Window(int width, int height) {
    Window(width, height, " ");
}
Window::Window(int width, int height, string background) : _width(width), _height(height) {
    for(int y=0;y<height;y++) {
        _canvas.push_back("");
        for(int x=0;x<width;x++) {
            _canvas[y] += background;
        }
    }
}

void Window::drawPanel(Panel& panel) {
    drawPanel(panel.x(), panel.y(), panel.width(), panel.height(), panel.contents());
}

void Window::drawPanel(int x, int y, Panel& panel) {
    drawPanel(x, y, panel.width(), panel.height(), panel.contents());
}

void Window::drawPanel(int x, int y, int width, int height, const vector<string>& contents) {

}

void Window::drawPanel(int x, int y, int width, int height) {
    
}

void Window::print() {
    
}