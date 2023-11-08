#include "WarriorWizard.h"

WarriorWizard::WarriorWizard(string name, int energy, int strength, int mana) :
    LivingThing(name, energy), Warrior(name, energy, strength), Wizard(name, energy, mana){}

WarriorWizard::~WarriorWizard() {

}
