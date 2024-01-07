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

    m_model = new PlayerTableModel(PlayerDatabase::instance()->players(), this);

    ui->playerTableView->setModel(m_model);

//    qDebug() <<

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    DialogAdd dlg;
    dlg.exec();
}


void MainWindow::on_editButton_clicked()
{
    DialogEdit dlg;
    dlg.exec();
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

