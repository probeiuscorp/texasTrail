#ifndef TEXAS_TRAIL_SHOP_H
#define TEXAS_TRAIL_SHOP_H
#include "world/City.h"
#include "TexasTrail.h"
#include "DialoguePrompt.h"
#include <string>

class Shop {
    public:
        using StringList = std::vector<std::string>;
        using string = std::string;
    public: 
        Shop();
        virtual ~Shop();

        string virtual name() const;

    private:
        string _name = "Ye Old Shoppe";
};

#endif