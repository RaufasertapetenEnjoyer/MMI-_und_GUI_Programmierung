#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QUrl"
#include "QDebug"
#include "imagefade.h"

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
        ImageFade imagefade(m_source, m_target, m_directory, m_steps);
        imagefade.start();
        imagefade.wait();
    }
}

void MainWindow::on_spinBoxSteps_textChanged(const QString &arg1)
{
    bool ok;
    int steps = arg1.toInt(&ok);

    if(ok){
        m_steps = steps;
    }else{
        qDebug() << "Irgendwas ist schiefgelaufen";
    }
}

void MainWindow::on_spinBoxSteps_valueChanged(int arg1)
{
    m_steps = arg1;
}
