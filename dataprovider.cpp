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

    QString apps[6] = {"ВКонтакте", "Telegram", "YouTube", "DachaMonitor", "MiFit", "Angry Birds"};
    QString contacts[6] = {"Ерохин", "Эдик", "Петя", "Макс", "Васян", "Мама"};
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

        StatEvent e(msg, QDateTime(QDate(2015, 03, 12), QTime(23, 38)));
        lst.append(e);
    }
    int min = 1;
    int max = 3;
    int output = min + (rand() % (int)(max - min + 1));
    sleep(1000 + (output * 1000));
    return lst;
}

