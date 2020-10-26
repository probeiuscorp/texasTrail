#ifndef TEXAS_TRAIL_UI_TRAVEL_H
#define TEXAS_TRAIL_UI_TRAVEL_H
#include "TexasTrail.h"
#include "UI.h"
#include "Utils.h"
#include "Colors.h"
#include "Formatting.h"
#include "Resources.h"
#include "render/Panel.h"
#include "render/Window.h"
// #include <chrono>
// #include <thread>
#include <iostream>
#include <sys/poll.h>
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
        const static int SML_PANEL_WIDTH = 24;
        const static int SML_PANEL_HEIGHT = 8;
        const static int POP_PANEL_WIDTH = 30;
        const static int POP_PANEL_HEIGHT = 12;
        const static int LRG_PANEL_WIDTH = 62;
        const static int LRG_PANEL_HEIGHT = 21;
        const static int POP_PANEL_OFFSET_X = SML_PANEL_WIDTH + LRG_PANEL_WIDTH/2 - POP_PANEL_WIDTH/2;
        const static int POP_PANEL_OFFSET_Y = LRG_PANEL_HEIGHT/2 - POP_PANEL_HEIGHT/2;
        const static int RGT_PANEL_OFFSET = SML_PANEL_WIDTH + LRG_PANEL_WIDTH;

    private:
        void setUITravel(bool paused);
        void readFrame(const Resource& resource, vector<string>* array) const;

    private:
        TexasTrail& _game;
        const UI& _ui;
        bool _exit = false;
        bool _frame = false;
        vector<string> _wagonFrame0;
        vector<string> _wagonFrame1;
        Panel _leftPanel;
        Panel _rightPanel;
        Panel _animPanel;
        Panel _popupPanel;
        Window _window;
        int _hour;

        string _dummy = "";
};

#endif