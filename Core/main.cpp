#include <QtGui/QApplication>
#include "cproject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CProject w;
    w.show();

    return a.exec();
}
