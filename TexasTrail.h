#ifndef TEXAS_TRAIL_H
#define TEXAS_TRAIL_H
#include <string>
#include <vector>
#include "Settings.h"
#include "UI.h"
// using std::string;
// using std::vector;

class TexasTrail {
public:
    using StringList = std::vector<std::string>;
    using Difficulty = Settings::Difficulty;

public: 
    TexasTrail();
    virtual ~TexasTrail();

    int run();
    void setDifficulty(Difficulty difficulty);
    Difficulty getDifficulty();
    void exit(int exit_status);

private: 
    Settings _settings;
    bool _exit;
    int _exit_status;

    void init();
};

#endif