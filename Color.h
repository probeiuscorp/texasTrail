#ifndef TEXAS_TRAIL_COLOR_H
#define TEXAS_TRAIL_COLOR_H

class Color {
    public:
        Color(int r, int g, int b);
        virtual ~Color() {}

        int red() const { return _r; }
        int green() const { return _g; }
        int blue() const { return _b; }

    private:
        int _r;
        int _g;
        int _b;  
};

#endif