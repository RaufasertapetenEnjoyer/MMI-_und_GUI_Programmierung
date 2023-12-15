
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

    void on_genderCBox_activated(int index);

    void on_nameEdit_textChanged(const QString &arg1);

    void on_orderLabel_clicked();

private:
    Ui::MainWindow *ui;
    bool m_payPerYearActive;

    double m_sum;
    QString m_name;
    QString m_gender;
    QString m_postalCode;
    QString m_IBAN;
    QString m_bank;
    QString m_paymentInterall;

    bool m_validName;
    bool m_genderTriggerdOnce;
    bool m_paymentIntervallTriggerdOnce;
    bool m_validIBAN;
    bool m_validPostalCode;

    void updateGui();
    void updateSum(bool checked);
    bool validIban(const QString&);
};

#endif // MAINWINDOW_H
