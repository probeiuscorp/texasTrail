#ifndef TEXAS_TRAIL_FORMATTING_H
#define TEXAS_TRAIL_FORMATTING_H
#include <string>

class Formatting {
public:
    enum class Color {
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        WHITE,
        CYAN,
        BLACK,
    };
    enum class Format {
        BOLD,
        ITALIC,
        UNDERLINE,
        FAINT,
    };
};

class Style {
public:
    static Style New(Formatting::Color color);
public:
    Style(Formatting::Color color);
    ~Style();
public:
    Style& with(Formatting::Format format);
    Style& with(Formatting::Format format, bool value);
    Style& color(Formatting::Color color);
    std::string text();
    Style& clear();
private:
    Formatting::Color _color;
    bool _bold = false;
    bool _italic = false;
    bool _underline = false;
    bool _faint = false;
};

#endif