#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "QImage"
#include "QUrl"
#include "QDebug"
#include "QThread"
#include "QString"
#include "imagefade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool compareFiles();

    bool canLoadFiles();

    void updateProgressBar(qreal percentage);

    void saveImage(QImage image);

    void setRunning(bool running);

    void displayMessage(QString message);

private slots:
    void on_buttonChooseSource_clicked();

    void on_pushChooseTarget_clicked();

    void on_pushChooseDirectory_clicked();

    void on_buttonGenerate_clicked();

    void on_spinBoxSteps_valueChanged(int arg1);

    void on_spinBoxSteps_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QThread* m_thread;
    ImageFade* m_fader;

    QImage m_source;
    QImage m_target;
    QUrl m_directory;
    int m_steps;
    bool m_running;
};
#endif // MAINWINDOW_H
