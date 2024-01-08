#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

QString DialogAdd::name() const
{
    return ui->nameEdit->text();
}

QDate DialogAdd::dateOfBirth() const
{
    return QDate::fromString(ui->dateEdit->text(),"dd.MM.yyyy");
}

QString DialogAdd::favouriteGenre() const
{
    return ui->genreEdit->text();
}
