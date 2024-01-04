#ifndef PLAYERDATABASE_H
#define PLAYERDATABASE_H

#include "QList"
#include "player.h"


class PlayerDatabase
{
private:
    PlayerDatabase();
    QList<Player> m_players;

public:
    static PlayerDatabase* instance();
    QList<Player>* players();
};

#endif // PLAYERDATABASE_H
