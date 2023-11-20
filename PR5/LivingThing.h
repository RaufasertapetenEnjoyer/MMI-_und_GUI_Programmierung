#ifndef MMI_UND_GUI_LIVINGTHING_H
#define MMI_UND_GUI_LIVINGTHING_H

#include "WorldThing.h"

class LivingThing : public WorldThing{
private:
    int m_energy;

public:
    LivingThing(string name, int energy);
    virtual ~LivingThing();

    virtual int getEnergy() const;
    void setEnergy(int energy);

    bool isDead() const;

    friend ostream& operator<<(ostream& os, const LivingThing& livingThing);

    virtual void operator-=(int energy);
};

ostream& operator<<(ostream& os, const LivingThing& livingThing);

#endif //MMI_UND_GUI_LIVINGTHING_H
