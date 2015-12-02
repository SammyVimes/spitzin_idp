#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <statevent.h>


class DataProvider
{
public:
    DataProvider();
    QList<StatEvent> getEventsForMsisdn(QString msisdn);
};

#endif // DATAPROVIDER_H
