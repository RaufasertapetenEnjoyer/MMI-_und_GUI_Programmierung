#include "userlistmodel.h"
#include <QDebug>

UserListModel::UserListModel(QList<Player>* players, QObject *parent)
    : QAbstractTableModel(parent), m_players(players)
{
}

QVariant UserListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section) {
            case 0: return "Genre";
            case 1: return "Name";
            case 2: return "Birthdate";
            }
        } else {
            return QString::number(section + 1);
        }
    }
    return QVariant();
}

int UserListModel::rowCount(const QModelIndex &) const
{
    return m_players->size();
}

int UserListModel::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant UserListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole) {
        const Player& player = m_players->at(index.row());
        QDate today = QDate::currentDate();
        auto age = today.year() - player.dateOfBirth().year();
        age = today.month() >= player.dateOfBirth().month() && today.day() >= player.dateOfBirth().day() ? age : age - 1;
        switch(index.column()) {
        case 0: return player.name();
        case 1: return age;
        case 2: return player.favouriteGenre();
        }
    }

    return QVariant();
}
