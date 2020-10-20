#ifndef TEXAS_TRAIL_UI_TRAVEL_H
#define TEXAS_TRAIL_UI_TRAVEL_H
#include "TexasTrail.h"
#include "UI.h"
#include "Utils.h"
#include "Colors.h"
#include "Formatting.h"
#include "Resources.h"
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
using std::string;

class UI;
class UITravel {
    public:
        UITravel(TexasTrail& game, const UI& ui);
        virtual ~UITravel();
    
        void run();

    private:
        void setUITravel();
        void readFrame(const Resource& resource, vector<string>* array) const;
    
    private:
        TexasTrail& _game;
        const UI& _ui;
        bool _exit = false;
        bool _frame = false;
        const int _plateSize = 24;
        const int _windowSize = 60;
        vector<string> _wagonFrame0;
        vector<string> _wagonFrame1;
};

#endif