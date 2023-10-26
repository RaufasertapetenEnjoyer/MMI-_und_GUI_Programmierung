//
// Created by jena- on 26.10.2023.
//

#include "PlayerDatabase.h"

PlayerDatabase::PlayerDatabase() {
    m_playerDatabase = new vector<Player>;
    cout << "PlayerDatabase created." << endl;
}

PlayerDatabase::~PlayerDatabase() {
    delete m_playerDatabase;
    cout << "PlayerDatabase destroyed." << endl;
}

void PlayerDatabase::addPlayer(Player& playerToAdd) {
    m_playerDatabase->push_back(playerToAdd);
}

void PlayerDatabase::clearDatabase() {
    m_playerDatabase->clear();
}

size_t PlayerDatabase::countPlayersInDatabase() {
    return m_playerDatabase->size();
}

Player &PlayerDatabase::operator[](int pos){
    vector<Player>& players = *m_playerDatabase;
    return players[pos];
}

Player &PlayerDatabase::operator[](int pos) const {
    vector<Player>& players = *m_playerDatabase;
    return players[pos];
}

ostream &operator<<(ostream &os, PlayerDatabase &playerDatabase) {
    for (const Player& player : *playerDatabase.m_playerDatabase) {
        os << player << endl;
    }
    return os;
}


