#ifndef TEXAS_TRAIL_SETTINGS_H
#define TEXAS_TRAIL_SETTINGS_H

class Settings {
public:
    enum class Difficulty {
        EASY,
        MEDIUM,
        HARD
    };
public: 
    Settings();
    virtual ~Settings();

    void setDifficulty(Difficulty difficulty);
    Difficulty getDifficulty();

private:
    Difficulty _difficulty = Difficulty::MEDIUM;
};

#endif