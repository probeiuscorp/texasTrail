#include "Immunity.h"

bool Immunity::has(EffectDisease* disease) {
    for(EffectDisease* _disease : _diseases) {
        if(disease == _disease) return true;
    }
    return false;
}