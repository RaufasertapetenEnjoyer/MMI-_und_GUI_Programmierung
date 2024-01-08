#ifndef USERMODEL_H
#define USERMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include "player.h"

class UserListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit UserListModel(QList<Player>* players, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    QList<Player>* m_players;
};

#endif // USERMODEL_H
