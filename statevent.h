#ifndef STATEVENT
#define STATEVENT

#include <QDateTime>
#include <QString>

class StatEvent {

public:
    StatEvent(QString eventText, QDateTime date) {
        this->eventText = eventText;
        this->date = date;
    }

    QString getEventText() {
        return eventText;
    }

    QDateTime getDate() {
        return date;
    }

private:
    QString eventText;
    QDateTime date;

};

#endif // STATEVENT

