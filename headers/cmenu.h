#ifndef CMENU_H
#define CMENU_H
#include <QString>
#include <QMap>
#include <QMenu>

class CMenu:public QMenu
{
    Q_OBJECT

public:

    QString static const FILE;
    QString static const TOOLS;
    QString static const EDIT;
    QString static const HELP;
    QString static const WINDOWS;

    QMap<QString, CMenu*> childList;
    QList<QAction*> actionList;
    /* Creates a CMenu with given name. Do not call it directly */
    CMenu(QWidget* parent, QString name);

    /* Returns the Name of the specified Menu */
    QString getName();

    /* Checks if the Menu has a child with specified Name */
    bool hasChildMenu(QString childName);

    /* Returns the CMenu Object if a child with specified name already exists
     * else inserts the child and returns its object
     */
    CMenu* getOrCreateChildMenu(QString childName);

    /* Returns the parent of the CMenu Object */
    CMenu* getParent();

    QAction* addMenuItem(QString name);
    // TODO: Image Resourse for Menu

};

#endif // CMENU_H
