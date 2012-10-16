#include "abell.h"
#include "ui_abell.h"

ABell::ABell(QWidget *parent, Dialog *d) :
    QDialog(parent),
    ui(new Ui::ABell),
    dia(d)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(setAlarm()));
    connect(&alarmTimer, SIGNAL(timeout()), this, SLOT(showMessage()));
}

ABell::~ABell()
{
    delete ui;
}

void ABell::setAlarm() {
    int t = this->ui->hrspin->value()*60+this->ui->minspin->value();
    alarmTimer.start(t*100000);
}
void ABell::showMessage() {
    dia->showText(this->ui->message->toPlainText());
}
