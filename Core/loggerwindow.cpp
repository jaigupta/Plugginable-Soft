#include "loggerwindow.h"
#include "ui_loggerwindow.h"

LoggerWindow::LoggerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoggerWindow)
{
    ui->setupUi(this);
}

LoggerWindow::~LoggerWindow()
{
    delete ui;
}

void LoggerWindow::setLog(QString &msg)
{
    ui->logArea->setText(msg);
}
