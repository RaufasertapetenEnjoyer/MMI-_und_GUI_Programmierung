#include "LivingThing.h"

LivingThing::LivingThing(string name, int energy): WorldThing(name), m_energy(energy) {}

LivingThing::~LivingThing() {

}

int LivingThing::getEnergy() const {
    return m_energy;
}

void LivingThing::setEnergy(int energy) {
    if(energy <= 0){
        m_energy = 0;
    }else{
        m_energy = energy;
    }
}

bool LivingThing::isDead() const {
    return m_energy == 0;
}

ostream &operator<<(ostream &os, const LivingThing &livingThing) {
    os << "Living Thing with the name " << livingThing.getName() << " and " << livingThing.m_energy << " energy." << endl;
    return os;
}

void LivingThing::operator-=(int energy) {
    this->setEnergy(this->getEnergy() - energy);
}
