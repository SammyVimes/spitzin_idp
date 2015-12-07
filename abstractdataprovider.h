#ifndef ABSTRACTDATAPROVIDER_H
#define ABSTRACTDATAPROVIDER_H

#include <QtSql>
#include <statevent.h>
#include <msisdn.h>
#include <coreutils.h>

class AbstractDataProvider
{
public:
    virtual QList<StatEvent> getEventsForMsisdn(MSISDN msisdn) = 0;
    virtual QList<StatEvent> selectByDateAndMsisdn(MSISDN msisdn, QDateTime dateTime) = 0;
    virtual void insertList(QList<StatEvent> list) = 0;
    virtual void insertVal(StatEvent e) = 0;
    virtual void init(QString dbName="db_name.sqlite") = 0;
    virtual QString close(QString dbName="db_name.sqlite") = 0;
    virtual QSqlDatabase _getDatabase() = 0;
};

#endif // ABSTRACTDATAPROVIDER_H
