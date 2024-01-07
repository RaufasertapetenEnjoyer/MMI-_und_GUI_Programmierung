#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include "QString"
#include "QDate"
#include "player.h"

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();

    QString name() const;

    QDate dateOfBirth() const;

    QString favouriteGenre() const;

private:
    Ui::DialogAdd *ui;

    QString m_name;
    QDate m_dateOfBirth;
    QString m_favouriteGenre;
};

#endif // DIALOGADD_H
