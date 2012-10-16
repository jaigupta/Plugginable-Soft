#ifndef DATASTORE_H
#define DATASTORE_H

#include <QTime>
#include <QTimer>
#include <QList>
/** A DataStore for out Alarm
  */
class DataStore
{
public:
    DataStore();
    QTime startTime;
    QList<QTimer> li;
};

#endif // DATASTORE_H
