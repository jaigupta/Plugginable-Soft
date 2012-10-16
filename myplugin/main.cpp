#include <QtGui/QApplication>
#include "firstplugin.h"
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstPlugin w;
    w.show();

    return a.exec();
}
