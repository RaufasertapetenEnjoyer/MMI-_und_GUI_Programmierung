#ifndef MMI_UND_GUI_WORLDTHING_H
#define MMI_UND_GUI_WORLDTHING_H
#include <iostream>

using namespace std;

class WorldThing {
private:
    string m_name;
public:
    WorldThing(string name);
    virtual ~WorldThing() = 0;

    string getName() const;
    void setName(string name);
};

#endif //MMI_UND_GUI_WORLDTHING_H

// PR5 CMakeList
// PR5/WorldThing.cpp
//        PR5/WorldThing.h
//        PR5/LivingThing.cpp
//        PR5/LivingThing.h
//        PR5/NPC.cpp
//        PR5/NPC.h
//        PR5/Stone.cpp
//        PR5/Stone.h
//        PR5/Plant.cpp
//        PR5/Plant.h
//        PR5/Warrior.cpp
//        PR5/Warrior.h
//        PR5/Wizard.cpp
//        PR5/Wizard.h
//        PR5/WarriorWizard.cpp
//        PR5/WarriorWizard.h
//        PR5/WizardThrong.cpp
//        PR5/WizardThrong.h