
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
    ui->ibanEdit->setMaxLength(7);
    ui->bankResultLabel->clear();
    ui->postalCodeInvalidLabel->clear();
    ui->priceSumLabel->setText("---- -, Euro");
    ui->postalCodeEdit->setMaxLength(5);
    ui->postalCodeEdit->setValidator(new QRegularExpressionValidator (QRegularExpression("[0-9]*")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGui(){
    ui->priceSumLabel->setText(QString::number(m_sum) + "-, Euro");
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
    if(!m_payPerYearActive && arg1 == "per year"){
        m_sum *= (1 - 0.05);
    }else if(m_payPerYearActive && arg1 == "per month"){
        m_sum /= (1 - 0.05);
    }
    arg1 == "per year" ? m_payPerYearActive = true : m_payPerYearActive = false;
    updateGui();
}


void MainWindow::on_postalCodeEdit_textChanged(const QString &arg1)
{
    if(arg1.length() != 5 && arg1.length() != 0){
        ui->postalCodeInvalidLabel->setText("The postal code is invalid!");
    }else{
        ui->postalCodeInvalidLabel->clear();
    }
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
                ui->bankResultLabel->setText("Bob the builder Bank");
            }else{
                ui->bankResultLabel->setText("unknown bank");
            }
            m_validIBAN = true;
        }else{
            ui->bankResultLabel->setText("Invalid IBAN!");
        }
    }else if(arg1.length() == 0){
        ui->bankResultLabel->clear();
        m_validIBAN = false;
    }else{
        ui->bankResultLabel->setText("Invalid IBAN!");
        m_validIBAN = false;
    }
}

