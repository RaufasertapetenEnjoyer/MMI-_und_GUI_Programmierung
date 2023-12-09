#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QObject>
#include <QDate>

class ShoppingCart : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("Description", "A shopping cart of an e-commerce shop")
    Q_PROPERTY(QString m_name READ getName WRITE setName)
    Q_PROPERTY(QDate m_date READ getDate WRITE setDate)
    Q_PROPERTY(double m_total READ getTotal WRITE setTotal)

public:
    explicit ShoppingCart(QString name, double total, QObject *parent = nullptr) : m_name(name), m_total(total),QObject(parent) {
        m_date = QDate::currentDate();
    }
    QString getName() const;
    QDate getDate() const;
    double getTotal() const;
    void setName(QString name);
    void setDate(QDate date);
    void setTotal(double total);

private:
    QString m_name;
    QDate m_date;
    double m_total;
};



#endif // SHOPPINGCART_H
