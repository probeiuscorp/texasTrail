#include "Diseases.h"
#include "DiseaseFactory.h"

void Diseases::load() {
    DiseaseFactory::start().setName("Chicken Pox").setDisplay("Chicken Pox: Very contagious. Very uncomfortable. Generally not lethal.")
        .setCommon(1.8).setDamage(0.25).setInfectivity(11.0).setCurability(2.0).create();
    DiseaseFactory::start().setName("the Flu").setDisplay("Influenza: Relatively non-lethal.")
        .setCommon(2.0).setDamage(0.3).setInfectivity(3.2).create();
    DiseaseFactory::start().setName("the common cold").setDisplay("Common cold: Annoying. Not dangerous.")
        .setCommon(3.0).setDamage(0.08).setInfectivity(2.1).create();
    DiseaseFactory::start().setName("Leukemia").setDisplay("Leukemia: Terminal cancer. Slow and insidious killer.")
        .setCommon(0.08).setDamage(0.4).setInfectivity(0).setCurability(0).create();
    DiseaseFactory::start().setName("Dysentery").setDisplay("Dysentary: Dangerous and diarrhetic.")
        .setCommon(1.6).setDamage(0.9).setInfectivity(7.6).setCurability(1.2).create();
}