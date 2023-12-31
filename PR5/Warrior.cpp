#include "Warrior.h"

Warrior::Warrior(string name, int energy, int strength) : LivingThing(name, energy), m_strength(strength){}

Warrior::~Warrior() {

}

int Warrior::getStrength() const {
    return this->isDead() ? 0 : m_strength;
}

void Warrior::setStrength(int strength) {
    if(!this->isDead()){
        m_strength = strength;
    }
}

ostream &operator<<(ostream &os, const Warrior &warrior) {
    os << "Warrior called " << warrior.getName() << " with " << warrior.getEnergy() << " energy and " << warrior.m_strength << " strength." << endl;
    return os;
}

void Warrior::operator>>(Warrior &warrior) {
    if(!this->isDead()) {
        if (warrior.isDead()) {
            cout << "Das ist unethisch, Du Tor!" << endl;
        } else {
            warrior.setEnergy(warrior.getEnergy() - this->getStrength());
        }
    }
}

void Warrior::operator>>(NPC &npc) {
    if(!this->isDead()) {
        if (!npc.isHittable()) {
            this->setEnergy(this->getEnergy() - 1);
        } else {
            npc.setEnergy(npc.getEnergy() - this->getStrength());
        }
    }
}


