#ifndef DIALOGSTAT_H
#define DIALOGSTAT_H

#include <QDialog>

namespace Ui {
class DialogStat;
}

class DialogStat : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStat(QWidget *parent = nullptr);
    ~DialogStat();

private:
    Ui::DialogStat *ui;
};

#endif // DIALOGSTAT_H
