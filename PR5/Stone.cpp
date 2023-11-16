#include "Stone.h"

Stone::Stone(string name) : NPC(name, 100, false){}

int Stone::getEnergy() const{
    return 100;
}

ostream &operator<<(ostream &os, const Stone &stone) {
    os << "Stone with the name " << stone.getName() << ", with " << stone.getEnergy() << " energy which is " << (stone.isHittable() ? "hittable" : "not hittable.") << endl;
    return os;
}
