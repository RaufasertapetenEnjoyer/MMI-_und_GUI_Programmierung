#include "Stone.h"

Stone::Stone(string name) : NPC(name, 100, false){}

int Stone::getEnergy() const{
    return 100;
}

ostream &operator<<(ostream &os, const Stone &stone) {
    os << "Stone with the name " << stone.getName() << ", with " << stone.getEnergy() << " which is " << (stone.isHittable() ? "hittable" : "not hittable");
    return os;
}
