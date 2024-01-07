#include "playerdatabase.h"
#include "QDebug"

PlayerDatabase::PlayerDatabase()
{
    m_players.append(Player("Max", QDate(2000, 1, 1), "Shooter"));
    m_players.append(Player("Michael", QDate(2002, 11, 2), "Shooter"));
    m_players.append(Player("Jan", QDate(2003, 3, 11), "Rätsel"));

    const QDate birthday = QDate(2000, 1, 1);
    const auto today = QDate::currentDate();
    auto age = today.year() - birthday.year();
    age = today.month() >= birthday.month() && today.day() >= birthday.day() ? age : age - 1;
    qDebug() << age;
}

PlayerDatabase* PlayerDatabase::instance()
{
    static PlayerDatabase* database = new PlayerDatabase();
    return database;
}

QList<Player>* PlayerDatabase::players()
{
    return &m_players;
}
