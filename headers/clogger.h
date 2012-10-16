#ifndef CLOGGER_H
#define CLOGGER_H
#include <QObject>
#include <QString>

class CLogger:public QObject
{
    Q_OBJECT

public:
    enum {
        DEBUG,
        WARNING,
        ERROR,
        INFO
    };

    /* Show Debug Info */
    void d(QString &);
    /* Show QWarning */
    void w(QString &);
    /* Show Error */
    void e(QString &);
    /* Show Info */
    void i(QString &);

signals:
    void logMsg(int, QString &);
};


#endif // CLOGGER_H
