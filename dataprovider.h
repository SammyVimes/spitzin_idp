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
    void insertList(QList<StatEvent> list);
    void insertVal(StatEvent e);
    void init(QString dbName="db_name.sqlite");
    QString close(QString dbName="db_name.sqlite");
    QSqlDatabase _getDatabase();
private:
    QSqlDatabase dataBase;
    QString dbName;
};

#endif // DATAPROVIDER_H
