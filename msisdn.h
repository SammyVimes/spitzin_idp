#ifndef MSISDN_H
#define MSISDN_H

#include <QString>


class MSISDN
{
public:
    MSISDN(QString msisdn);
    MSISDN();
    QString getMsisdn();
private:
    QString msisdn;
};

#endif // MSISDN_H
