#include "Panel.h"

// Panel::Panel() {}
Panel::Panel(int width, int height) : _x(0), _y(0), _width(width), _height(height), _contents(vector<string>()) {

}
Panel::Panel(int width, int height, vector<string>& contents) : _x(0), _y(0), _width(width), _height(height), _contents(contents) {

}
Panel::Panel(int x, int y, int width, int height) : _x(x), _y(y), _width(width), _height(height), _contents(vector<string>()) {

}
Panel::Panel(int x, int y, int width, int height, vector<string>& contents) : _contents(contents), _x(x), _y(y), _width(width), _height(height) {

}