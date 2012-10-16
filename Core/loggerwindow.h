#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include <QDialog>

namespace Ui {
    class LoggerWindow;
}

class LoggerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoggerWindow(QWidget *parent = 0);
    ~LoggerWindow();
    void setLog(QString&);

private:
    Ui::LoggerWindow *ui;
};

#endif // LOGGERWINDOW_H
