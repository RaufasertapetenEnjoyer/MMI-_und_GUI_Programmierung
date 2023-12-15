
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_sum = 0;
    m_payPerYearActive = false;
    m_validIBAN = false;
    m_paymentIntervallTriggerdOnce = false;
    m_validName = false;
    m_genderTriggerdOnce = false;

    ui->paymentIntervallCBox->setPlaceholderText(" ");
    ui->paymentIntervallCBox->addItem("per month");
    ui->paymentIntervallCBox->addItem("per year");

    ui->genderCBox->setPlaceholderText(" ");
    ui->genderCBox->addItem("male");
    ui->genderCBox->addItem("female");
    ui->genderCBox->addItem("diverse");

    ui->ibanEdit->setMaxLength(7);

    ui->bankResultLabel->clear();

    ui->nameEdit->setValidator(new QRegularExpressionValidator (QRegularExpression("[a-zA-Z ]*")));

    ui->postalCodeInvalidLabel->clear();
    ui->postalCodeEdit->setMaxLength(5);
    ui->postalCodeEdit->setValidator(new QRegularExpressionValidator (QRegularExpression("[0-9]*")));

    ui->priceSumLabel->setText("---- -, Euro");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGui(){
    if(m_paymentIntervallTriggerdOnce == true){
       ui->priceSumLabel->setText(QString::number(m_sum) + "-, Euro");
    }
}

void MainWindow::updateSum(bool checked){
    if(m_payPerYearActive){
        m_sum /= (1 - 0.05);
        if(checked){
            m_sum += 1000;
        }else{
            m_sum -= 1000;
        }
        m_sum *= (1 - 0.05);
    }else{
        if(checked){
            m_sum += 1000;
        }else{
            m_sum -= 1000;
        }
    }
    updateGui();
}

void MainWindow::on_emergencyMarketRB_clicked(bool checked)
{
    updateSum(checked);
}


void MainWindow::on_tecRB_clicked(bool checked)
{
    updateSum(checked);
}


void MainWindow::on_asiaRB_clicked(bool checked)
{
    updateSum(checked);
}


void MainWindow::on_europeRB_clicked(bool checked)
{
    updateSum(checked);
}


void MainWindow::on_chinaRB_clicked(bool checked)
{
    updateSum(checked);
}

void MainWindow::on_paymentIntervallCBox_textActivated(const QString &arg1)
{
    m_paymentIntervallTriggerdOnce = true;
    if(!m_payPerYearActive && arg1 == "per year"){
        m_paymentInterall = "per year";
        m_sum *= (1 - 0.05);
    }else if(m_payPerYearActive && arg1 == "per month"){
        m_paymentInterall = "per month";
        m_sum /= (1 - 0.05);
    }
    arg1 == "per year" ? m_payPerYearActive = true : m_payPerYearActive = false;
    updateGui();
}

void MainWindow::on_postalCodeEdit_textChanged(const QString &arg1)
{
    if(arg1.length() != 5 && arg1.length() != 0){
        m_validPostalCode = false;
        m_postalCode = "";
        ui->postalCodeInvalidLabel->setText("The postal code is invalid!");
        return;
    }else if(arg1.length() == 5){
        m_postalCode = arg1;
        m_validPostalCode = true;
    }
    ui->postalCodeInvalidLabel->clear();
}

bool MainWindow::validIban(const QString& iban){
    if((iban.at(0).isLetter() && iban.at(0).isUpper()) && (iban.at(1).isLetter() && iban.at(1).isUpper())){
        for(int i = 2; i < 7; i++){
            if(!iban.at(i).isDigit()){
                return false;
            }
        }
        return true;
    }
    return false;
}

void MainWindow::on_ibanEdit_textChanged(const QString &arg1)
{
    if(arg1.length() == 7){
        if(validIban(arg1)){
            if(arg1 == "DE12345"){
                m_bank = "Bob the builder Bank";
                ui->bankResultLabel->setText("Bob the builder Bank");
            }else{
                m_bank = "unknown bank";
                ui->bankResultLabel->setText("unknown bank");
            }
            m_IBAN = arg1;
            m_validIBAN = true;
        }else{
            ui->bankResultLabel->setText("Invalid IBAN!");
            m_validIBAN = false;
            m_IBAN = "";
        }
    }else if(arg1.length() == 0){
        ui->bankResultLabel->clear();
        m_validIBAN = false;
        m_IBAN = "";
    }else{
        ui->bankResultLabel->setText("Invalid IBAN!");
        m_validIBAN = false;
        m_IBAN = "";
    }
}

void MainWindow::on_genderCBox_activated(int index)
{
    switch (index) {
    case 0:
        m_gender = "male";
        break;
    case 1:
        m_gender = "female";
        break;
    case 2:
        m_gender = "diverse";
        break;
    default:
        break;
    }
    m_genderTriggerdOnce = true;
}


void MainWindow::on_nameEdit_textChanged(const QString &arg1)
{
    if(arg1.length() >= 5 && (arg1.at(0).isLetter() && arg1.at(arg1.length() - 1).isLetter() && arg1.contains(" "))){
        m_validName = true;
        m_name = arg1;
    }else{
        m_validName = false;
        m_name = "";
    }
}


void MainWindow::on_orderLabel_clicked()
{
    if(m_validName
        && m_sum != 0
        && m_validName
        && m_genderTriggerdOnce
        && m_validIBAN
        && m_validPostalCode
        && m_paymentIntervallTriggerdOnce){
        qDebug() << " name:              " << m_name << "\n"
                 << "gender:            " << m_gender << "\n"
                 << "postal code:       " << m_postalCode << "\n"
                 << "IBAN:              " << m_IBAN << "\n"
                 << "bank:              " << m_bank << "\n"
                 << "payment intervall: " << m_paymentInterall << "\n"
                 << "sum of order:      " << QString::number(m_sum);
    }else{
        qDebug() << "Can't order papers, because the given data is invalid!";
    }
}

