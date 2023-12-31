#ifndef MMI_UND_GUI_WARRIORWIZARD_H
#define MMI_UND_GUI_WARRIORWIZARD_H

#include "Warrior.h"
#include "Wizard.h"

class WarriorWizard : public Wizard, public Warrior{
public:
    WarriorWizard(string name, int energy, int strength, int mana);
    virtual ~WarriorWizard();

    friend ostream& operator<<(ostream& os, WarriorWizard& warriorWizard);
};

ostream& operator<<(ostream& os, WarriorWizard& warriorWizard);

#endif //MMI_UND_GUI_WARRIORWIZARD_H
