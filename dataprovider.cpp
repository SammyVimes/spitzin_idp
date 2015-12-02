#include "dataprovider.h"
#include <QTimer>
#include <QEventLoop>

void sleep(qint64 msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

DataProvider::DataProvider()
{

}

QList<StatEvent> DataProvider::getEventsForMsisdn(QString msisdn)
{

    QList<StatEvent> lst;
    for (int i = 0; i < 10; i++) {
        StatEvent e(QString("Hello, Niko"), QDateTime(QDate(2007, 10, 25), QTime(23, 38)));
        lst.append(e);
    }
    int min = 1;
    int max = 3;
    int output = min + (rand() % (int)(max - min + 1));
    sleep(1000 + (output * 1000));
    return lst;
}

