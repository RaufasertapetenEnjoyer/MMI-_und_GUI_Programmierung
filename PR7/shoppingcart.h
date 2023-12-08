#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QObject>

class ShoppingCart : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("Description", "A shopping cart of an e-commerce shop")
    Q_PROPERTY(type m_name READ getName WRITE setName)
    Q_PROPERTY(type m_date READ getDate WRITE setDate)
    Q_PROPERTY(type m_total READ getTotal WRITE setTotal)

public:
    explicit ShoppingCart(QObject *parent = nullptr);
    ShoppingCart(QString name, double total): m_name(name), m_total(total) {
        date = currentDate();
    };
    QString getName() const;
    QDate getDate() const;
    double getTotal() const;
    void setName();
    void setDate();
    void setTotal();

private:
    QString m_name;
    QDate m_date;
    double m_total;

signals:

};



#endif // SHOPPINGCART_H
