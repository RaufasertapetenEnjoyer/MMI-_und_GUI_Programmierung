#include "PlayerDataBaseWithPointers.h"

PlayerDataBaseWithPointers::PlayerDataBaseWithPointers() {
    m_playerDatabase = new vector<Player*>;
    cout << "PlayerDatabase created." << endl;
}

PlayerDataBaseWithPointers::~PlayerDataBaseWithPointers() {
    delete m_playerDatabase;
    cout << "PlayerDatabase destroyed." << endl;
}

void PlayerDataBaseWithPointers::addPlayer(Player* playerToAdd) const{
    m_playerDatabase->push_back(playerToAdd);
}

void PlayerDataBaseWithPointers::clearDatabase() const{
    m_playerDatabase->clear();
}

size_t PlayerDataBaseWithPointers::countPlayersInDatabase() const{
    return m_playerDatabase->size();
}

Player* PlayerDataBaseWithPointers::operator[](const int& pos){
    vector<Player*>& players = *m_playerDatabase;
    return players[pos];
}

const Player* PlayerDataBaseWithPointers::operator[](int pos) const {
    vector<Player*>& players = *m_playerDatabase;
    return players[pos];
}

ostream &operator<<(ostream &os, PlayerDataBaseWithPointers &playerDatabase) {
    for (const Player* player : *playerDatabase.m_playerDatabase) {
        os << *player << endl;
    }
    return os;
}


