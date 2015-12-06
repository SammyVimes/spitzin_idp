#include "msisdn.h"

MSISDN::MSISDN(QString msisdn)
{
    this->msisdn = msisdn;
}

MSISDN::MSISDN()
{
    this->msisdn = "";
}

QString MSISDN::getMsisdn()
{
    return msisdn;
}

