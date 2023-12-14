
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_emergencyMarketRB_clicked(bool checked);

    void on_tecRB_clicked(bool checked);

    void on_asiaRB_clicked(bool checked);

    void on_europeRB_clicked(bool checked);

    void on_chinaRB_clicked(bool checked);

    void on_paymentIntervallCBox_textActivated(const QString &arg1);

    void on_postalCodeEdit_textChanged(const QString &arg1);

    void on_ibanEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    double m_sum;
    bool m_payPerYearActive;
    bool m_validIBAN;
    bool m_validPostalCode;

    void updateGui();
    void updateSum(bool checked);
    bool validIban(const QString&);
};

#endif // MAINWINDOW_H
