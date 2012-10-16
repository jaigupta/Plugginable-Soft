#include "firstplugin.h"
#include "ui_firstplugin.h"

FirstPlugin::FirstPlugin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirstPlugin)
{
    ui->setupUi(this);
    d = new Dialog();

}

FirstPlugin::~FirstPlugin()
{
    delete ui;
}

QString FirstPlugin::pluginName() const
{
    return "Hello World Plugin";
}

QString FirstPlugin::smallDetail() const
{
    return "Small Detail";
}

QString FirstPlugin::largeDetail() const
{
    return "Large Detail of the Plugin to be entered here. "
            "The UI components may use this to explain more about the plugin to user";
}

void FirstPlugin::entryPoint(UiStore* mainUi, Project* proj)
{
    CMenu* rootMenu = mainUi->getRootMenu();
    CMenu* timerMenu = rootMenu->getOrCreateChildMenu("Timer");
    QAction* showTimerMenu = timerMenu->addMenuItem("Show Time Spent");
    QAction* addAlarmMenu = timerMenu->addMenuItem("addAlarm");
    connect(showTimerMenu, SIGNAL(triggered()), this, SLOT(showTimerMenu_clicked()));
    connect(addAlarmMenu, SIGNAL(triggered()), this, SLOT(addAlarmMenu_clicked()));
    QString msg = "This is a message";
    //proj->logger->w(msg);
}

void FirstPlugin::showTimerMenu_clicked() {
    int tspent = dataStore.startTime.elapsed()/1000;
    int sec = tspent%60;
    tspent /= 60;
    int min = tspent%60;
    tspent /= 60;
    d->showText(QString("Time spent on this software is: \n%1 Hrs %2 Mins %3 Secs.").arg(QString::number(tspent), QString::number(min), QString::number(sec)));
    d->show();
}

void FirstPlugin::addAlarmMenu_clicked() {
    ABell *b = new ABell(this, d);
    b->exec();
    //b->setAlarm("hi", 10000);

}

QT_BEGIN_NAMESPACE
Q_EXPORT_PLUGIN2(timerPlugin, FirstPlugin)
QT_END_NAMESPACE
