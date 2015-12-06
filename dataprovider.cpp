#include "dataprovider.h"
#include <QTimer>
#include <QEventLoop>

/**

MOCK

**/


void sleep(qint64 msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

DataProvider::DataProvider()
{

}

QList<StatEvent> dbSelect(QSqlDatabase db, MSISDN msisdn, QDateTime dateTime) {
    QSqlQuery q(db);
    QDateTime start(dateTime.date());
    long startMillis = start.toTime_t();

    QDateTime end(dateTime.date());
    end = end.addDays(1);
    long endMillis = end.toTime_t();

    q.prepare("SELECT * FROM events WHERE msisdn=:msisdn"
              " AND event_Date>:startMillis AND event_date<:endMillis");
    q.bindValue(":msisdn", msisdn.getMsisdn());
    q.bindValue(":startMillis", ((unsigned long long) startMillis));
    q.bindValue(":endMillis", ((unsigned long long) endMillis));
    if (!q.exec()) {
        return QList<StatEvent>();
    }
    QList<StatEvent> lst;
    while (q.next()) {
        long long _date = q.value(2).toLongLong();
        QString text = q.value(3).toString();
        QDateTime dateTime = QDateTime::fromTime_t(_date);
        StatEvent s(msisdn, text, dateTime);
        lst.append(s);
    }
    return lst;
}

void _insertVal(QSqlDatabase db, StatEvent e) {
    QSqlQuery q(db);
    q.prepare("INSERT INTO events (msisdn, event_date, event_text)"
              " VALUES(:msisdn, :event_date, :event_text)");
    q.bindValue(":msisdn", e.getMsisdn().getMsisdn());
    q.bindValue(":event_date", e.getDate().toTime_t());
    q.bindValue(":event_text", e.getEventText());
    if (!q.exec()) {
        QSqlError err = q.lastError();
        QString errText = err.text();
        return;
    }
}

void _insertLst(QSqlDatabase db, QList<StatEvent> data) {
    foreach (StatEvent event, data) {
        _insertVal(db, event);
    }
}

QList<StatEvent> DataProvider::getEventsForMsisdn(MSISDN msisdn)
{
    QList<StatEvent> _tmp = dbSelect(dataBase, msisdn, QDateTime::currentDateTime());
    if (_tmp.size() > 0) {
        return _tmp;
    }
    QString apps[6] = {"ВКонтакте", "Telegram", "YouTube", "DachaMonitor", "MiFit", "Angry Birds"};
    QString contacts[6] = {"Папа", "Эдик", "Петя", "Макс", "Васян", "Мама"};
    QString osEvent[6] = {"Включение устройства", "Выключение устройства", "Тревога!", "Попытка отключения", "Test1", "Test2"};
    QString netEvent[6] = {"www.yandex.ru", "youtube.com", "codeforce.com", "bash.org", "wikipedia.ru", "maythe4.com"};

    QList<StatEvent> lst;
    for (int i = 0; i < 20; i++) {

        int min = 0;
        int max = 3;
        int output = min + (rand() % (int)(max - min + 1));

        int _min = 0;
        int _max = 5;
        int _output = min + (rand() % (int)(max - min + 1));

        QString msg;

        switch(output) {
        case 0:
            msg = "Запущено приложение '" + apps[_output] + "'";
            break;
        case 1:
            msg = "Звонок от '" + contacts[_output] + "'";
            break;
        case 2:
            msg = osEvent[_output];
            break;
        case 3:
            msg = "Посещение '" + netEvent[_output] + "'";
            break;
        }

        StatEvent e(msisdn, msg, QDateTime::currentDateTime());
        lst.append(e);
    }
    _insertLst(dataBase, lst);
    //sleep(1000 + random(1000, 3000));
    return lst;
}

QList<StatEvent> DataProvider::selectByDateAndMsisdn(MSISDN msisdn, QDateTime dateTime)
{
    QList<StatEvent> _tmp = dbSelect(dataBase, msisdn, dateTime);
    if (_tmp.size() > 0) {
        return _tmp;
    }
    QString apps[6] = {"ВКонтакте", "Telegram", "YouTube", "DachaMonitor", "MiFit", "Angry Birds"};
    QString contacts[6] = {"Папа", "Эдик", "Петя", "Макс", "Васян", "Мама"};
    QString osEvent[6] = {"Включение устройства", "Выключение устройства", "Тревога!", "Попытка отключения", "Test1", "Test2"};
    QString netEvent[6] = {"www.yandex.ru", "youtube.com", "codeforce.com", "bash.org", "wikipedia.ru", "maythe4.com"};

    QList<StatEvent> lst;
    for (int i = 0; i < 20; i++) {

        int min = 0;
        int max = 3;
        int output = min + (rand() % (int)(max - min + 1));

        int _min = 0;
        int _max = 5;
        int _output = min + (rand() % (int)(max - min + 1));

        QString msg;

        switch(output) {
        case 0:
            msg = "Запущено приложение '" + apps[_output] + "'";
            break;
        case 1:
            msg = "Звонок от '" + contacts[_output] + "'";
            break;
        case 2:
            msg = osEvent[_output];
            break;
        case 3:
            msg = "Посещение '" + netEvent[_output] + "'";
            break;
        }
        int hour = random(0, 23);
        int minute = random(0, 59);
        StatEvent e(msisdn, msg, QDateTime(dateTime.date(), QTime(hour, minute)));
        lst.append(e);
    }
    _insertLst(dataBase, lst);
    //sleep(1000 + random(1000, 3000));
    return lst;
}

void DataProvider::init()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("db_name.sqlite");
    if (!dataBase.open()) {
        throw 0;
    }
    if (!dataBase.tables().contains(QLatin1String("events"))) {
        QSqlQuery a_query(dataBase);
        QString str = "CREATE TABLE events ("
                "number integer PRIMARY KEY NOT NULL, "
                "msisdn VARCHAR(255), "
                "event_date integer, "
                "event_text VARCHAR(255)"
                ");";
        bool b = a_query.exec(str);
        if (!b) {
            throw 1;
        }
    }
}
