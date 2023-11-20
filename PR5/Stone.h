#ifndef MMI_UND_GUI_STONE_H
#define MMI_UND_GUI_STONE_H

#include "NPC.h"

class Stone : public NPC{
public:
    Stone(string name);

    int getEnergy() const override;

    friend ostream& operator<<(ostream& os, const Stone& stone);
};

ostream& operator<<(ostream& os, const Stone& stone);

#endif //MMI_UND_GUI_STONE_H
