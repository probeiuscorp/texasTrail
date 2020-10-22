#include "CanvasElement.h"

CanvasElement::CanvasElement() {
    CanvasElement(" ");
}
CanvasElement::CanvasElement(string str) {
    _str = str;
}
CanvasElement::~CanvasElement() {}

string CanvasElement::str() {
    return _str;
}