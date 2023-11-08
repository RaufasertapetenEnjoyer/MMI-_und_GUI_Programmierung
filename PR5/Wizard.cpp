#include "Wizard.h"

Wizard::Wizard(string name, int energy, int mana) : LivingThing(name, energy), m_mana(mana){}

Wizard::~Wizard() {

}

int Wizard::getMana() const {
    return this->isDead() ? 0 : m_mana;
}

void Wizard::setMana(int mana) {
    if(!this->isDead()){
        m_mana = mana;
    }
}

ostream &operator<<(ostream &os, const Wizard &wizard) {
    os << "Wizard called " << wizard.getName() << " with " << wizard.getEnergy() << " energy " << " and " << wizard.m_mana << " mana." << endl;
    return os;
}

void Wizard::operator>>(Warrior &warrior) {
    if(!this->isDead()){
        warrior.setEnergy(warrior.getEnergy() - static_cast<int>(round(this->m_mana / 10)));
    }
}

void Wizard::operator>>(Wizard &wizard) {
    if(!this->isDead()) {
        if (this->m_mana > 0) {
            this->m_mana--;
        } else {
            this->setEnergy(this->getEnergy() - 1);
        }
        wizard.m_mana++;
    }
}