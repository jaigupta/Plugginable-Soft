#ifndef CPROJECT_H
#define CPROJECT_H
#include <QObject>
#include "clogger.h"
class Project:public QObject
{
    Q_OBJECT

public:
    Project();
    CLogger *logger;
};
#endif // CPROJECT_H
