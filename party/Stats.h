#ifndef TEXAS_TRAIL_STATS_H
#define TEXAS_TRAIL_STATS_H

class Stats {
    public:
        Stats() {}
        virtual ~Stats() {}

        // height in inches
        double height = -1;
        // height in weight
        double weight = -1;
        // age in years
        int age = -1;
        // 1.0 is average
        double strength = 1;
        // 1.0 is average
        double intelligence = 1;
};

#endif