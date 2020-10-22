#ifndef TEXAS_TRAIL_CANVAS_ELEMENT_H
#define TEXAS_TRAIL_CANVAS_ELEMENT_H
#include <string>
using std::string;

class CanvasElement {
    public:
        CanvasElement();
        CanvasElement(string str);
        virtual ~CanvasElement();

        virtual string str();
        virtual void setStr(string str) { _str = str; }
        virtual void setStr(const char* str) { _str = string(str); }
        virtual void setStr(char str) { _str = string(1, str); }
    private:
        string _str;
};

#endif