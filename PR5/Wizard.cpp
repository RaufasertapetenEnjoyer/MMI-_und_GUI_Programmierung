#include "Wizard.h"

Wizard::Wizard(string name, int energy, int mana) : LivingThing(name, energy), m_mana(mana){}

Wizard::~Wizard() {

}

ostream &operator<<(ostream &os, const Wizard &wizard) {
    os << "Wizard called " << wizard.getName() << " with " << wizard.getEnergy() << " energy " << " and " << wizard.m_mana << " mana." << endl;
    return os;
}
