#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <statevent.h>
#include <msisdn.h>
#include <coreutils.h>


class DataProvider
{
public:
    DataProvider();
    QList<StatEvent> getEventsForMsisdn(QString msisdn);
    QList<StatEvent> selectByDateAndMsisdn(MSISDN msisdn, QDateTime dateTime);
};

#endif // DATAPROVIDER_H
