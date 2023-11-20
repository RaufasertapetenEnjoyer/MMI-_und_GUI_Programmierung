#ifndef MMI_UND_GUI_PLANT_H
#define MMI_UND_GUI_PLANT_H

#include "NPC.h"

class Plant : public NPC{

public:
    Plant(string name, int energy);

    friend ostream& operator<<(ostream &, const Plant& plant);
};

ostream& operator<<(ostream &os, const Plant& plant);

#endif //MMI_UND_GUI_PLANT_H
