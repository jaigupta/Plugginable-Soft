#ifndef ABELL_H
#define ABELL_H

#include <QDialog>
#include <QTimer>
#include "dialog.h"

namespace Ui {
    class ABell;
}

class ABell : public QDialog
{
    Q_OBJECT

public:
    explicit ABell(QWidget *parent = 0, Dialog *d = 0);
    ~ABell();

public slots:
    void setAlarm();
    void showMessage();
private:
    Ui::ABell *ui;
    Dialog *dia;
    QTimer alarmTimer;
};

#endif // ABELL_H
