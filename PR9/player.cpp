#include "player.h"

Player::Player()
{

}

Player::Player(QString name, QDate dateOfBirth, QString favouriteGenre) :
    m_name(name), m_dateOfBirth(dateOfBirth), m_favouriteGenre(favouriteGenre)
{

}


QString Player::name() const
{
    return m_name;
}

void Player::setName(const QString &newName)
{
    m_name = newName;
}

QDate Player::dateOfBirth() const
{
    return m_dateOfBirth;
}

void Player::setDateOfBirth(const QDate &newDateOfBirth)
{
    m_dateOfBirth = newDateOfBirth;
}

QString Player::favouriteGenre() const
{
    return m_favouriteGenre;
}

void Player::setFavouriteGenre(const QString &newFavouriteGenre)
{
    m_favouriteGenre = newFavouriteGenre;
}
