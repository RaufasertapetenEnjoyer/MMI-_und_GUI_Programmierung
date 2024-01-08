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

int DialogEdit::getIndex() const
{
    return m_index;
}

void DialogEdit::setIndex(int newIndex)
{
    m_index = newIndex;
}

QString DialogEdit::name() const
{
    return ui->nameEdit->text();
}

void DialogEdit::setName(const QString &newName)
{
    m_name = newName;
}

QDate DialogEdit::dateOfBirth() const
{
    return QDate::fromString(ui->dateEdit->text(),"dd.MM.yyyy");
}

void DialogEdit::setDateOfBirth(const QDate &newDateOfBirth)
{
    m_dateOfBirth = newDateOfBirth;
}

QString DialogEdit::favouriteGenre() const
{
    return ui->genreEdit->text();
}

void DialogEdit::setFavouriteGenre(const QString &newFavouriteGenre)
{
    m_favouriteGenre = newFavouriteGenre;
}
