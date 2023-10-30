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

    void addPlayer(const Player& playerToAdd) const;

    void clearDatabase() const;

    size_t countPlayersInDatabase() const;

    const Player& operator[](int pos) const;
    Player& operator[](const int& pos);

    friend ostream& operator<<(ostream& os, PlayerDatabase& player);
};

ostream& operator<<(ostream& os, PlayerDatabase& playerDatabase);

#endif //MMI_UND_GUI_PLAYERDATABASE_H
