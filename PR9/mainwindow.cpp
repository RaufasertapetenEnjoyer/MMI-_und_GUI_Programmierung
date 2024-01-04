#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdatabase.h"
#include "QList"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new PlayerTableModelAlt(PlayerDatabase::instance()->players(), this);

    ui->playerTableView->setModel(m_model);

    qDebug(PlayerDatabase::instance()->players()->toList());
}

MainWindow::~MainWindow()
{
    delete ui;
}

