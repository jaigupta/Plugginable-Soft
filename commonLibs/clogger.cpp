#include "../headers/clogger.h"
void CLogger::d(QString& msg)
{
    emit logMsg(DEBUG, msg);
}

void CLogger::e(QString& msg)
{
    emit logMsg(ERROR, msg);
}

void CLogger::w(QString& msg)
{
    emit logMsg(WARNING, msg);
}
void CLogger::i(QString& msg)
{
    emit logMsg(INFO, msg);
}

