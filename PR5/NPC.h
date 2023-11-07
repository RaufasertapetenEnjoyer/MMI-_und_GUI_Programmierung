#ifndef MMI_UND_GUI_NPC_H
#define MMI_UND_GUI_NPC_H

#include "LivingThing.h"

class NPC : public LivingThing{
private:
    const bool m_hittable;
public:
    NPC(string name, int energy, bool hittable);

    bool isHittable() const;

    friend ostream& operator<<(ostream& os, const NPC& npc);
};

ostream& operator<<(ostream& os, const NPC& npc);

#endif //MMI_UND_GUI_NPC_H
