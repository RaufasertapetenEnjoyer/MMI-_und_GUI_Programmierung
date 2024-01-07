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
    return m_name;
}

QDate DialogAdd::dateOfBirth() const
{
    return m_dateOfBirth;
}

QString DialogAdd::favouriteGenre() const
{
    return m_favouriteGenre;
}
