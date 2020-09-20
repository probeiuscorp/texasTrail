#include "Formatting.h"

Style::Style(Formatting::Color color) {
    _color = color;
}

Style::~Style(){}

Style Style::New(Formatting::Color color) {
    return Style(color);
}

Style& Style::with(Formatting::Format format) {
    return with(format, true);
}

Style& Style::with(Formatting::Format format, bool value) {
    switch(format) {
        case Formatting::Format::BOLD:
            _bold = value;
            break;
        case Formatting::Format::ITALIC:
            _italic = value;
            break;
        case Formatting::Format::UNDERLINE:
            _underline = value;
            break;
        case Formatting::Format::FAINT:
            _faint = value;
            break;
   }

   return *this;
}

Style& Style::clear() {
    _bold = false;
    _italic = false;
    _underline = false;
    _faint = false;

    return *this;
}

std::string Style::text() {
    std::string string = "\033[";
    if(_bold) {
        string += "01;";
    }
    if(_faint) {
        string += "02;";
    }
    if(_italic) {
        string += "03;";
    }
    if(_underline) {
        string += "04;";
    }
    switch(_color) {
        case Formatting::Color::RED:
            string += "31";
            break;
        case Formatting::Color::GREEN:
            string += "32";
            break;
        case Formatting::Color::YELLOW:
            string += "33";
            break;
        case Formatting::Color::BLUE:
            string += "34";
            break;
        case Formatting::Color::MAGENTA:
            string += "35";
            break;
        case Formatting::Color::CYAN:
            string += "36";
            break;
        case Formatting::Color::WHITE:
            string += "37";
            break;
        case Formatting::Color::BLACK:
            string += "30";
            break;

    }
    string += "m";
    return string;
}