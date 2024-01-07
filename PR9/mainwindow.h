#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QList"

#include "playertablemodel.h"
#include "playertablemodelalt.h"
#include "dialogadd.h"
#include "dialogedit.h"
#include "dialogdel.h"
#include "dialogstat.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_statButton_clicked();

private:
    Ui::MainWindow *ui;

    PlayerTableModel* m_model;
};
#endif // MAINWINDOW_H
