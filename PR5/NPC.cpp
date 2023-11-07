#include "NPC.h"

NPC::NPC(string name, int energy, bool hittable) : LivingThing(name, energy), m_hittable(hittable){}

bool NPC::isHittable() const {
    return m_hittable;
}

ostream &operator<<(ostream &os, const NPC &npc) {
    os << "NPC with the name " << npc.getName() << ", with " << npc.getEnergy() << " which is " << (npc.m_hittable ? "hittable" : "not hittable") << endl;
    return os;
}
