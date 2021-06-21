#include "ItemMedicine.h"
#include "Person.h"
#include "Effect.h"
#include "EffectDisease.h"
#include "Utils.h"

bool ItemMedicine::usableOnPerson(Person* person) const {
    for(Effect* effect : person->effects()) {
        if(dynamic_cast<EffectDisease*>(effect) != nullptr) {
            return true;
        }
    }
    return false;
}

string ItemMedicine::useOnPerson(Person* person) const {
    for(Effect* effect : person->effects()) {
        EffectDisease* disease = dynamic_cast<EffectDisease*>(effect);
        if(disease != nullptr && disease->curability() == 0.0) {
            if(Utils::chance(0.3 * disease->curability())) {
                person->removeEffect(effect);
                return "Succesfully cured " + disease->name();
            } else {
                return "Failed curing of " + disease->name();
            }
        }
    }
    return "No disease was encountered.";
}