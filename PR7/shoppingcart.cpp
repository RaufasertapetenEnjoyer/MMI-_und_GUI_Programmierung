#include "shoppingcart.h"

QString ShoppingCart::getName() const{
    return m_name;
}

QDate ShoppingCart::getDate() const{
    return m_date;
}

double ShoppingCart::getTotal() const{
    return m_total;
}

void ShoppingCart::setName(QString name){
    m_name = name;
}

void ShoppingCart::setDate(QDate date) {
    m_date = date;
}

void ShoppingCart::setTotal(double total){
    m_total = total;
}
