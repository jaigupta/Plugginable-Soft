#ifndef MYINTERFACE_H
#define MYINTERFACE_H
#include <QtPlugin>
#include "../headers/uistore.h"
#include "../headers/project.h"

QT_BEGIN_NAMESPACE
class QObject;
QT_END_NAMESPACE

class PluginInterface
{
public:
    virtual ~PluginInterface(){}
    virtual QString pluginName() const = 0;
    virtual QString smallDetail() const = 0;
    virtual QString largeDetail() const = 0;
    virtual void    entryPoint(UiStore*, Project*) = 0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(PluginInterface, "com.jai.CProject.plugin/1.0")

QT_END_NAMESPACE
#endif // MYINTERFACE_H
