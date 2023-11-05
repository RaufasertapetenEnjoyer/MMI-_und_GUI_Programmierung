#ifndef MMI_UND_GUI_PLAYERDATABASEWITHPOINTERS_H
#define MMI_UND_GUI_PLAYERDATABASEWITHPOINTERS_H
#include <iostream>
#include <vector>
#include "Player.h"

class PlayerDataBaseWithPointers {
private:
    std::vector<Player*>* m_playerDatabase;
public:
    PlayerDataBaseWithPointers();
    ~PlayerDataBaseWithPointers();

    void addPlayer(Player* playerToAdd) const;

    void clearDatabase() const;

    size_t countPlayersInDatabase() const;

    const Player* operator[](int pos) const;
    Player* operator[](const int& pos);

    friend ostream& operator<<(ostream& os, PlayerDataBaseWithPointers& player);
};

ostream& operator<<(ostream& os, PlayerDataBaseWithPointers& playerDatabase);



#endif //MMI_UND_GUI_PLAYERDATABASEWITHPOINTERS_H
