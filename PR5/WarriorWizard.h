#ifndef MMI_UND_GUI_WARRIORWIZARD_H
#define MMI_UND_GUI_WARRIORWIZARD_H

#include "Warrior.h"
#include "Wizard.h"

class WarriorWizard : virtual public Wizard, virtual public Warrior{
    //TODO virtuelle Basisklasse entweder hier oder dann bei Warrior und Wizard
    //TODO <<operator
};


#endif //MMI_UND_GUI_WARRIORWIZARD_H
