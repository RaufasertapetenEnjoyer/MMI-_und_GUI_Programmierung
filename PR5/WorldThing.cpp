#include "WorldThing.h"

WorldThing::WorldThing(string name) : m_name(name){}

string WorldThing::getName() const{
    return m_name;
}

void WorldThing::setName(string name) {
    m_name = name;
}