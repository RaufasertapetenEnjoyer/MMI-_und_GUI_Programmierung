#ifndef MMI_UND_GUI_WIZARD_H
#define MMI_UND_GUI_WIZARD_H

#include "LivingThing.h"
#include "Warrior.h"
#include <cmath>

class Wizard : virtual public LivingThing{
private:
    int m_mana;

public:
    Wizard(string name, int energy, int mana);
    virtual ~Wizard();

    int getMana() const;
    void setMana(int mana);

    friend ostream& operator<<(ostream& os, const Wizard& wizard);

    void operator>>(Warrior& warrior);

    void operator>>(Wizard& wizard);
};

ostream& operator<<(ostream& os, const Wizard& wizard);

#endif //MMI_UND_GUI_WIZARD_H
