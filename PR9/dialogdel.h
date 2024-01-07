#ifndef DIALOGDEL_H
#define DIALOGDEL_H

#include <QDialog>
#include "QString"
#include "QDate"
#include "player.h"

namespace Ui {
class DialogDel;
}

class DialogDel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDel(QWidget *parent = nullptr);
    ~DialogDel();

private:
    Ui::DialogDel *ui;

    int index;
};

#endif // DIALOGDEL_H
