#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>
#include "../headers/uistore.h"
#include "../headers/project.h"
#include "loggerwindow.h"

namespace Ui {
    class MainWindow;
}

class CProject : public QMainWindow
{
    Q_OBJECT

public:
    explicit CProject(QWidget *parent = 0);
    UiStore* data;
    Project* project;
    ~CProject();

private:
    QString logMessage;
    bool showLogs;
    LoggerWindow *logwin;

    Ui::MainWindow *ui;
    void loadPlugins();
    void createMenuStructure();

public slots:
    void logMsg(int, QString&);
};

#endif // MAINWINDOW_H
