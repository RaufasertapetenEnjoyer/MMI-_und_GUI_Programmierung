#include "playertablemodel.h"
#include "QDebug"

PlayerTableModel::PlayerTableModel(QList<Player>* players, QObject *parent)
    : QAbstractItemModel(parent), m_players(players)
{
}

QVariant PlayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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
    return QVariant();
}

bool PlayerTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

QModelIndex PlayerTableModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex PlayerTableModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int PlayerTableModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return 0;
    } else {
        return m_players->size();
    }
}

int PlayerTableModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return 0;
    } else {
        return 3;
    }
}

QVariant PlayerTableModel::data(const QModelIndex &index, int role) const
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

/**
bool PlayerTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags PlayerTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return  Qt::ItemIsEditable;
}

bool PlayerTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool PlayerTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    qDebug() << "Forbidden";
    endInsertColumns();
    return true;
}

bool PlayerTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

bool PlayerTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    qDebug() << "Forbidden";
    endRemoveColumns();
    return true;
}
**/

int PlayerTableModel::calculateAge(const QDate dateOfBirth)
{
    const QDate today = QDate::currentDate();
    auto age = today.year() - dateOfBirth.year();
    return today.month() >= dateOfBirth.month() && today.day() >= dateOfBirth.day() ? age : age - 1;
}
