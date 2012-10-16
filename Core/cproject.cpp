#include "cproject.h"
#include "ui_mainwindow.h"
#include "../headers/PluginInterface.h"
#include "../headers/clogger.h"

CProject::CProject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data = new UiStore();
    data->RootMenu = new CMenu(this, "Root");
    project = new Project();
    logMessage = "";
    showLogs = true;
    logwin = NULL;
    connect(project->logger, SIGNAL(logMsg(int, QString&)), this, SLOT(logMsg(int, QString&)));
    loadPlugins();
    createMenuStructure();
}

CProject::~CProject()
{
    delete ui;
}

void CProject::createMenuStructure()
{
    QMenuBar* menuBar = new QMenuBar(this);
    QMapIterator <QString, CMenu*> i(data->RootMenu->childList);
    while(i.hasNext())
    {
        i.next();
        menuBar->addMenu(i.value());
    }
    if(data->RootMenu->actionList.length()>0)
    {
        qDebug()<<"Cannot Add MenuItem to root Menu. Try Adding to a childMenu of RootMenu";
    }
    this->setMenuBar(menuBar);
}

void CProject::loadPlugins()
{
    CMenu* pluginMenu = this->data->getRootMenu()->getOrCreateChildMenu("Plugins");
    // Loading the Plugins
    foreach (QObject *plugin, QPluginLoader::staticInstances()){
        qDebug()<<"Found static plugin";
        if (plugin) {
            qDebug()<<"Found Static Linked Plugin";
            PluginInterface *userPlugin = qobject_cast<PluginInterface *>(plugin);
            if(userPlugin)
            {
                pluginMenu->addMenuItem(userPlugin->pluginName());
                userPlugin->entryPoint(this->data, this->project);
            }
        }
    }

    QDir pluginsDir = QDir(qApp->applicationDirPath());

     #if defined(Q_OS_WIN)
         if (pluginsDir.dirName().toLower() == "debug" ||
                 pluginsDir.dirName().toLower() == "release")
             pluginsDir.cdUp();
     #elif defined(Q_OS_MAC)
         if (pluginsDir.dirName() == "MacOS") {
             pluginsDir.cdUp();
             pluginsDir.cdUp();
             pluginsDir.cdUp();
         }
     #endif
         pluginsDir.cd("plugins");
     foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
          QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
          qDebug()<<"Loading... "<<fileName;
          QObject *plugin = loader.instance();
          if(!loader.isLoaded())
          {
              qDebug()<<"Plugin not loaded... "<<loader.errorString();
          }
          if (plugin) {
              qDebug()<<"Found Plugin in "<<fileName;
              PluginInterface *userPlugin = qobject_cast<PluginInterface *>(plugin);
               if(userPlugin)
               {
                   pluginMenu->addMenuItem(userPlugin->pluginName());
                   userPlugin->entryPoint(this->data, this->project);
               }
          }
    }
    // End of loading the plugins
}

void CProject::logMsg(int type, QString& msg)
{
    switch(type)
    {
        case CLogger::DEBUG:
            logMessage += "<b>DEBUG:</b> ";
            break;
        case CLogger::ERROR:
            logMessage += "<b>ERROR:</b> ";
            break;
        case CLogger::WARNING:
            logMessage += "<b>WARNING:</b> ";
            break;
        case CLogger::INFO:
            logMessage += "<b>INFO:</b> ";
            break;
    }
    logMessage += "<br/>";

    this->logMessage += msg;
    if(this->showLogs)
    {
        if(logwin == NULL)
            logwin = new LoggerWindow(this);
        logwin->setLog(logMessage);
        logwin->show();
    }
}
