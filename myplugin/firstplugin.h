#ifndef FIRSTPLUGIN_H
#define FIRSTPLUGIN_H

#include <QWidget>
#include "../headers/PluginInterface.h"
#include <QtGui>
#include "datastore.h"
#include "dialog.h"
#include "abell.h"

namespace Ui {
    class FirstPlugin;
}

class FirstPlugin : public QWidget, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)

public:
    explicit FirstPlugin(QWidget *parent = 0);
    ~FirstPlugin();
    virtual QString pluginName() const;
    virtual QString smallDetail() const;
    virtual QString largeDetail() const;
    virtual void    entryPoint(UiStore*, Project*);
public slots:
    void showTimerMenu_clicked();
    void addAlarmMenu_clicked();
private:
    Ui::FirstPlugin *ui;
    Dialog *d;
    DataStore dataStore;
};

#endif // FIRSTPLUGIN_H
