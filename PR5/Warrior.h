#ifndef MMI_UND_GUI_WARRIOR_H
#define MMI_UND_GUI_WARRIOR_H

#include "LivingThing.h"
#include "NPC.h"

class Warrior : virtual public LivingThing{
private:
    int m_strength;

public:
    Warrior(string name, int energy, int strength);
    virtual ~Warrior();

    int getStrength() const;
    void setStrength(int strength);

    friend ostream& operator<<(ostream& os, const Warrior& warrior);

    void operator>>(Warrior& warrior);

    void operator>>(NPC& npc);
};

ostream& operator<<(ostream& os, const Warrior& warrior);

#endif //MMI_UND_GUI_WARRIOR_H
