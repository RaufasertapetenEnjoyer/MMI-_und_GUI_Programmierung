#include "playerdatabase.h"

PlayerDatabase::PlayerDatabase()
{
    m_players.append(Player("Max", QDate(2000, 1, 1), "Shooter"));
}

PlayerDatabase* PlayerDatabase::instance()
{
    static PlayerDatabase* database = new PlayerDatabase;
    return database;
}

QList<Player>* PlayerDatabase::players()
{
    return &m_players;
}
