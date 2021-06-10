#include "Event.h"

Event::~Event() {
    delete _popup;
    delete _prompt;
}