#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include "abstractdataprovider.h"
#include <QtSql>
#include <statevent.h>
#include <msisdn.h>
#include <coreutils.h>


class DataProvider : public AbstractDataProvider
{
public:
    DataProvider();
    QList<StatEvent> getEventsForMsisdn(MSISDN msisdn) override;
    QList<StatEvent> selectByDateAndMsisdn(MSISDN msisdn, QDateTime dateTime) override;
    void insertList(QList<StatEvent> list) override;
    void insertVal(StatEvent e) override;
    void init(QString dbName="db_name.sqlite") override;
    QString close(QString dbName="db_name.sqlite") override;
    QSqlDatabase _getDatabase() override;
private:
    QSqlDatabase dataBase;
    QString dbName;
};

#endif // DATAPROVIDER_H
