#include "WarriorWizard.h"

WarriorWizard::WarriorWizard(string name, int energy, int strength, int mana) :
    LivingThing(name, energy), Warrior(name, energy, strength), Wizard(name, energy, mana){}

WarriorWizard::~WarriorWizard() {

}

ostream &operator<<(ostream &os, WarriorWizard &warriorWizard) {
    os << "Warriorwizard with the name " << warriorWizard.getName() << " with " << warriorWizard.getEnergy() << " energy, " << warriorWizard.getStrength() << " strength and " << warriorWizard.getMana() << " mana." << endl;
    return os;
}
