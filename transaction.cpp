#include "transaction.h"
#include <QString>
Transaction::Transaction(QString Date, QString Amount, QString Type, QString Description, QString Repo)
{
    this->date = Date;
    this->amount = Amount;
    this->description = Description;
    this->type = Type;
    this->repo = Repo;
}

QString Transaction::getDate(){
    return this->date;
}

QString Transaction::getAmount(){
    return  this->amount;
}

QString Transaction::getDescription(){
    return this->description;
}

QString Transaction::getType(){
    return this->type;

}

QString Transaction::getRepo(){
    return this->repo;
}
