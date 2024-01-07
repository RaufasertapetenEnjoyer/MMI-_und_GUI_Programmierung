#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>
#include "QString"
#include "QDate"
#include "player.h"

namespace Ui {
class DialogEdit;
}

class DialogEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEdit(QWidget *parent = nullptr);
    ~DialogEdit();



    QString name() const;
    void setName(const QString &newName);

    QDate dateOfBirth() const;
    void setDateOfBirth(const QDate &newDateOfBirth);

    QString favouriteGenre() const;
    void setFavouriteGenre(const QString &newFavouriteGenre);

private:
    Ui::DialogEdit *ui;

    QString m_name;
    QDate m_dateOfBirth;
    QString m_favouriteGenre;
};

#endif // DIALOGEDIT_H
