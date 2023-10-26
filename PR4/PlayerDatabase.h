//
// Created by jena- on 26.10.2023.
//

#ifndef MMI_UND_GUI_PLAYERDATABASE_H
#define MMI_UND_GUI_PLAYERDATABASE_H
#include <iostream>
#include <vector>
#include "Player.h"

class PlayerDatabase {
private:
    std::vector<Player>* m_playerDatabase;
public:
    PlayerDatabase();
    ~PlayerDatabase();

    void addPlayer(Player& playerToAdd);

    void clearDatabase();

    size_t countPlayersInDatabase();

    Player& operator[](int pos) const;
    Player& operator[](int pos);

    friend ostream& operator<<(ostream& os, PlayerDatabase& player);
};

ostream& operator<<(ostream& os, PlayerDatabase& playerDatabase);

#endif //MMI_UND_GUI_PLAYERDATABASE_H
