#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdatabase.h"
#include "QList"
#include "QAction"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new UserListModel(PlayerDatabase::instance()->players(), this);

    ui->playerTableView->setModel(m_model);

    ui->playerTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < PlayerDatabase::instance()->players()->size(); i++)
    {
        qDebug() << PlayerDatabase::instance()->players()->at(i).name() << " " << PlayerDatabase::instance()->players()->at(i).dateOfBirth() << " " << PlayerDatabase::instance()->players()->at(i).favouriteGenre();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI()
{
    m_model = new UserListModel(PlayerDatabase::instance()->players(), this);

    ui->playerTableView->setModel(m_model);

    for (int i = 0; i < PlayerDatabase::instance()->players()->size(); i++)
    {
        qDebug() << PlayerDatabase::instance()->players()->at(i).name() << " " << PlayerDatabase::instance()->players()->at(i).dateOfBirth() << " " << PlayerDatabase::instance()->players()->at(i).favouriteGenre();
    }
}

void MainWindow::on_addButton_clicked()
{
    DialogAdd dlg;
    if (dlg.exec() == QDialog::Accepted) {
        PlayerDatabase::instance()->players()->append(Player(dlg.name(), dlg.dateOfBirth(), dlg.favouriteGenre()));
        updateUI();
    }
}


void MainWindow::on_editButton_clicked()
{
    DialogEdit dlg;
    if (dlg.exec() == QDialog::Accepted) {
//        PlayerDatabase::instance()->players()[dlg.getIndex()].setName(dlg.name());
//        PlayerDatabase::instance()->players()->at(dlg.getIndex()).setDateOfBirth(dlg.dateOfBirth());
//        PlayerDatabase::instance()->players()->at(dlg.getIndex()).setFavouriteGenre(dlg.favouriteGenre());
        updateUI();
    }
}


void MainWindow::on_delButton_clicked()
{
    DialogDel dlg;
    dlg.exec();
}

void MainWindow::on_statButton_clicked()
{
    DialogStat dlg;
    dlg.exec();
}

