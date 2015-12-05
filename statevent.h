#ifndef STATEVENT
#define STATEVENT

#include <QDateTime>
#include <QString>
#include <msisdn.h>

class StatEvent {

public:
    StatEvent(MSISDN msisdn, QString eventText, QDateTime date) {
        this->eventText = eventText;
        this->date = date;
        this->msisdn = msisdn;
    }

    QString getEventText() {
        return eventText;
    }

    QDateTime getDate() {
        return date;
    }

    MSISDN getMsisdn() {
        return msisdn;
    }

private:
    QString eventText;
    QDateTime date;
    MSISDN msisdn;
};

#endif // STATEVENT

