#ifndef TEXAS_TRAIL_WORLD_H
#define TEXAS_TRAIL_WORLD_H

class World {
    public: 
        World();
        virtual ~World();
        
    private: 
        Settings _settings;
        Party _party;
};

#endif