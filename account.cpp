#include "account.h"
#include <QString>
Account::Account(QString passCode)
{
    this->passcode = passCode;
}

QString Account::getPasscode(){
    return this->passcode;
}
