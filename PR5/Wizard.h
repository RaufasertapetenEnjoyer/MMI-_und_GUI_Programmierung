#ifndef MMI_UND_GUI_WIZARD_H
#define MMI_UND_GUI_WIZARD_H

#include "LivingThing.h"
#include "Warrior.h"

class Wizard : public LivingThing{
private:
    int m_mana;

public:
    Wizard(string name, int energy, int mana);
    virtual ~Wizard();

    friend ostream& operator<<(ostream& os, const Wizard& wizard);

    void operator>>(Warrior& warrior);
};

ostream& operator<<(ostream& os, const Wizard& wizard);

#endif //MMI_UND_GUI_WIZARD_H
