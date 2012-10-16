#include "../headers/cmenu.h"

// Initialising Static constant members
const QString CMenu::FILE  = "File";
const QString CMenu::EDIT  = "Edit";
const QString CMenu::TOOLS = "Tools";
const QString CMenu::HELP  = "Help";
const QString CMenu::WINDOWS = "Windows";

CMenu::CMenu(QWidget* parent, QString name):
    QMenu(parent)
{
    this->setObjectName(name);
    this->setTitle(name);
}

QString CMenu::getName()
{
    return this->objectName();
}

bool CMenu::hasChildMenu(QString childName)
{
    return childList.contains(childName);
}

CMenu*  CMenu::getOrCreateChildMenu(QString childName)
{
    if(!this->hasChildMenu(childName)) {
        childList[childName] = new CMenu(this, childName);
        this->addMenu(childList[childName]);
        this->addAction(childList[childName]->menuAction());
    }
    return childList[childName];
}

CMenu* CMenu::getParent()
{
    return qobject_cast<CMenu*>(this->parent());
}

QAction* CMenu::addMenuItem(QString name)
{
    QAction* myAction = new QAction(this);
    myAction->setObjectName(name);
    this->addAction(myAction);
    myAction->setText(name);
    this->actionList.append(myAction);
    return myAction;
}
