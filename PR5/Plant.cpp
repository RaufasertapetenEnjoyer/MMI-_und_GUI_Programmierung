#include "Plant.h"

Plant::Plant(string name, int energy) : NPC(name, energy, true) {}

ostream &operator<<(ostream &os, const Plant &plant) {
    os << "Plant with the name " << plant.getName() << ", with " << plant.getEnergy() << " which is " << (plant.isHittable() ? "hittable" : "not hittable");
    return os;
}
