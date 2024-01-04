#ifndef PLAYER_H
#define PLAYER_H

#include "QString"
#include "QDate"

class Player
{
public:
    Player();
    Player(QString name, QDate dateOfBirth, QString favouriteGenre);

    QString name() const;
    void setName(const QString &newName);

    QDate dateOfBirth() const;
    void setDateOfBirth(const QDate &newDateOfBirth);

    QString favouriteGenre() const;
    void setFavouriteGenre(const QString &newFavouriteGenre);

private:
    QString m_name;
    QDate m_dateOfBirth;
    QString m_favouriteGenre;
};

#endif // PLAYER_H
