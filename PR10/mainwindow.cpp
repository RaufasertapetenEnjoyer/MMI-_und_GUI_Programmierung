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

    ui->morphingProgressBar->setRange(0, 100);
    ui->morphingProgressBar->setValue(0);

    m_thread = new QThread();
    m_fader = new ImageFade();
    m_running = false;

    connect(m_fader, &ImageFade::updateBar, this, &MainWindow::updateProgressBar);
    connect(m_fader, &ImageFade::stillRunning, this, &MainWindow::setRunning);
    connect(m_fader, &ImageFade::sendMessage, this, &MainWindow::displayMessage);

    m_fader->moveToThread(m_thread);
    m_thread->start();

}

MainWindow::~MainWindow()
{
    m_thread->requestInterruption();
    m_thread->quit();
    m_thread->wait();
    delete m_thread;
    delete m_fader;


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

void MainWindow::updateProgressBar(qreal percentage)
{
    ui->morphingProgressBar->setValue(percentage);
}

void MainWindow::setRunning(bool running)
{
    m_running = running;
}

void MainWindow::displayMessage(QString message)
{
    ui->outputText->appendPlainText(message);
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
    if (!m_running) {
        ui->outputText->appendPlainText("Program started.");
        if (compareFiles() && canLoadFiles()) {
            QMetaObject::invokeMethod(m_fader, "run", Q_ARG(const QImage&, m_source), Q_ARG(const QImage&, m_target), Q_ARG(const QUrl&, m_directory),  Q_ARG(int,  m_steps));
        } else {
            ui->outputText->appendPlainText("Bilder konnten nicht geladen werden oder sind nicht kompatibel.");
        }
    } else {
        ui->outputText->appendPlainText("Program aborted.");
        m_thread->requestInterruption();
        m_thread->quit();
        m_running = false;
    }

}

void MainWindow::on_spinBoxSteps_textChanged(const QString &arg1)
{
    bool ok;
    int steps = arg1.toInt(&ok);

    if(ok){
        m_steps = steps;
    }else{
        ui->outputText->appendPlainText("Irgendwas ist schiefgelaufen");
    }
}

void MainWindow::on_spinBoxSteps_valueChanged(int arg1)
{
    m_steps = arg1;
}
