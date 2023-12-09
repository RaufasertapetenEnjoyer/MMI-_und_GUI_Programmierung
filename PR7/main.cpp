#include "mainwindow.h"
#include "shoppingcart.h"

#include <QDebug>
#include <QMetaClassInfo>
#include <QApplication>

int main(int argc, char *argv[])
{
    ShoppingCart* cart = new ShoppingCart("Cart 1", 100.1);
    qDebug() << cart->metaObject()->className();
    for (int i = 0; i<cart->metaObject()->classInfoCount(); i++) {
        QMetaClassInfo info = cart->metaObject()->classInfo(i);
        qDebug() << info.name() << " = " << info.value();
    }
    qDebug() << "Name: " << cart->getName() << "\nTotal: " << cart->getTotal() << "\nDate: " << cart->getDate().toString("yyyy-MM-dd");
    cart->setProperty("m_name", "Cart 2");
    cart->setProperty("m_total", 0.0);
    cart->setProperty("m_date", QDate::currentDate());
    qDebug() << "Name: " << cart->getName() << "\nTotal: " << cart->getTotal() << "\nDate: " <<  cart->getDate().toString("yyyy-MM-dd");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
