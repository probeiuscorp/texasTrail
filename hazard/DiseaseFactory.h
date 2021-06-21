#ifndef TEXAS_TRAIL_DISEASE_FACTORY_H
#define TEXAS_TRAIL_DISEASE_FACTORY_H
#include "HazardDisease.h"
#include <string>
using std::string;

class DiseaseFactory {
    public:
        static  DiseaseFactory& start();
        virtual DiseaseFactory& setName(string name);
        virtual DiseaseFactory& setDisplay(string display);
        // 1.0 is default: Takes around 21 days to kill a 100 health person.
        virtual DiseaseFactory& setDamage(double damage);
        // 1.0 is default: Takes 
        virtual DiseaseFactory& setCommon(double chance);
        // 1.0 is default: Around 10% more likely to catch for every other infected person.
        virtual DiseaseFactory& setInfectivity(double infectious);
        // 1.0 is default: A very healthy person is likely to cure themself after 5 days.
        virtual DiseaseFactory& setCurability(double curability);
        virtual HazardDisease* create();

    private:
        string _name;
        string _display;
        double _damage = 1.0;
        double _common = 1.0;
        double _infectious = 1.0;
        double _curability = 1.0;
};

#endif