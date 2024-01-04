#include "playertablemodelalt.h"

PlayerTableModelAlt::PlayerTableModelAlt(QList<Player>* players, QObject *parent)
    : QAbstractItemModel(parent) , m_players(players)
{
}

QVariant PlayerTableModelAlt::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch(section) {
            case 0: return "Name";
            case 1: return "Alter";
            case 2: return "Lieblingsgenre";
            }
        } else {
            return QString::number(section + 1);
        }
    }
}

QModelIndex PlayerTableModelAlt::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex PlayerTableModelAlt::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int PlayerTableModelAlt::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return 0;
    } else {
        return m_players->size();
    }
}

int PlayerTableModelAlt::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return 0;
    } else {
        return 3;
    }
}

QVariant PlayerTableModelAlt::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        const Player& player = m_players->at(index.row());
        switch(index.column()) {
        case 0: return player.name();
        case 1: return player.dateOfBirth();
        case 2: return player.favouriteGenre();
        }
    }
    return QVariant();
}
