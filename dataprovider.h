#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QtSql>
#include <statevent.h>
#include <msisdn.h>
#include <coreutils.h>


class DataProvider
{
public:
    DataProvider();
    QList<StatEvent> getEventsForMsisdn(MSISDN msisdn);
    QList<StatEvent> selectByDateAndMsisdn(MSISDN msisdn, QDateTime dateTime);
    void init();
private:
    QSqlDatabase dataBase;
};

#endif // DATAPROVIDER_H
