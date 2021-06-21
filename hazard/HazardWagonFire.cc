#include "HazardWagonFire.h"
#include "EventGeneric.h"
#include "Utils.h"
#include "party/Wagon.h"
#include "TexasTrail.h"

void HazardWagonFire::tryToApply(Wagon* subject, TexasTrail* game, int hours) {
    double chance = 1.0/(2);
    printf("Wagon: %p\n", subject);

    for(int i=0;i<hours;i++) {
        if(Utils::chance(chance)) {
            printf("Wagon succesfully caught on fire.\n");
            string popup = string("The wagon caught fire! " + std::to_string(subject->size()) + " stacks were lost.");
            printf("%s\n", popup.c_str());
            subject->addEvent(new EventGeneric(popup));
            Wagon::StackList stacks = subject->stacks();
            auto it = stacks.begin();
            while(it != stacks.end()) {
                delete *it;
                it++;
            }
            stacks.clear();
            return;
        }
    }
}