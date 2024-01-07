#include "dialogstat.h"
#include "ui_dialogstat.h"

DialogStat::DialogStat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStat)
{
    ui->setupUi(this);
}

DialogStat::~DialogStat()
{
    delete ui;
}
