#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "QImage"
#include "QUrl"
#include "QDebug"

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

    void updateProgressBar();

    void saveImage(QImage image);

private slots:
    void on_buttonChooseSource_clicked();

    void on_pushChooseTarget_clicked();

    void on_pushChooseDirectory_clicked();

    void on_buttonGenerate_clicked();

    void on_spinBoxSteps_valueChanged(int arg1);

    void on_spinBoxSteps_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QImage m_source;
    QImage m_target;
    QUrl m_directory;
    int m_steps;
};
#endif // MAINWINDOW_H
