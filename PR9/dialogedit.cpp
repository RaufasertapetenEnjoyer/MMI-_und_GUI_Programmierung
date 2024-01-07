#include "dialogedit.h"
#include "ui_dialogedit.h"

DialogEdit::DialogEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEdit)
{
    ui->setupUi(this);
}

DialogEdit::~DialogEdit()
{
    delete ui;
}

QString DialogEdit::name() const
{
    return m_name;
}

void DialogEdit::setName(const QString &newName)
{
    m_name = newName;
}

QDate DialogEdit::dateOfBirth() const
{
    return m_dateOfBirth;
}

void DialogEdit::setDateOfBirth(const QDate &newDateOfBirth)
{
    m_dateOfBirth = newDateOfBirth;
}

QString DialogEdit::favouriteGenre() const
{
    return m_favouriteGenre;
}

void DialogEdit::setFavouriteGenre(const QString &newFavouriteGenre)
{
    m_favouriteGenre = newFavouriteGenre;
}
