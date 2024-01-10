#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QUrl"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::compareFiles()
{
    return m_source.size() == m_target.size();
}

bool MainWindow::canLoadFiles()
{
    return true;
}

void MainWindow::updateProgressBar()
{

}

void MainWindow::saveImage(QImage image)
{

}

void MainWindow::on_buttonChooseSource_clicked()
{
    QStringList formats = {"Images (*.PNG *.png *.JPG *.jpg *.JPEG *jpeg"};
    QFileDialog dlg;
    dlg.setWindowTitle("Select source image");
    dlg.setNameFilter(formats.join(";;"));
    if (dlg.exec() == QFileDialog::Accepted) {
        QStringList fileNames;
        fileNames = dlg.selectedFiles();

        QImage source(fileNames.at(0));

        m_source = source;

        ui->lineEditSource->setText(fileNames.at(0));
    }
}

void MainWindow::on_pushChooseTarget_clicked()
{
    QStringList formats = {"Images (*.PNG *.png *.JPG *.jpg *.JPEG *jpeg"};
    QFileDialog dlg;
    dlg.setWindowTitle("Select target image");
    dlg.setNameFilter(formats.join(";;"));
    if (dlg.exec() == QFileDialog::Accepted) {
        QStringList fileNames;
        fileNames = dlg.selectedFiles();

        QImage target(fileNames.at(0));

        m_target = target;

        ui->lineEditTarget->setText(fileNames.at(0));
    }
}

void MainWindow::on_pushChooseDirectory_clicked()
{
    QFileDialog dlg;
    dlg.setFileMode(QFileDialog::Directory);
    if (dlg.exec() == QFileDialog::Accepted) {
        QUrl directory;
        directory = dlg.directoryUrl();

        m_directory = directory;

        ui->lineEditDirectory->setText(directory.toString());
    }
}

void MainWindow::on_buttonGenerate_clicked()
{
    if (compareFiles() && canLoadFiles()) {

    }
}


void MainWindow::on_spinBoxSteps_valueChanged(int arg1)
{
    m_steps = arg1;
}

