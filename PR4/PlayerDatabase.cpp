#include "PlayerDatabase.h"

PlayerDatabase::PlayerDatabase() {
    m_playerDatabase = new vector<Player>;
    m_playerDatabase->reserve(4);
    cout << "PlayerDatabase created." << endl;
}

PlayerDatabase::~PlayerDatabase() {
    delete m_playerDatabase;
    cout << "PlayerDatabase destroyed." << endl;
}

void PlayerDatabase::addPlayer(const Player& playerToAdd) const{
    m_playerDatabase->push_back(playerToAdd);
}

void PlayerDatabase::clearDatabase() const{
    m_playerDatabase->clear();
}

size_t PlayerDatabase::countPlayersInDatabase() const{
    return m_playerDatabase->size();
}

Player &PlayerDatabase::operator[](const int& pos){
    vector<Player>& players = *m_playerDatabase;
    return players[pos];
}

const Player &PlayerDatabase::operator[](int pos) const {
    vector<Player>& players = *m_playerDatabase;
    return players[pos];
}

ostream &operator<<(ostream &os, PlayerDatabase &playerDatabase) {
    for (const Player& player : *playerDatabase.m_playerDatabase) {
        os << player << endl;
    }
    return os;
}


