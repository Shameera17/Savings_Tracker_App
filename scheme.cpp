#include "scheme.h"

Scheme::Scheme(QString Scheme1name, QString Scheme2name, QString Scheme3name, QString Scheme4name, int Scheme1Perc, int Scheme2Perc, int Scheme3Perc, int Scheme4Perc)
{
    this->Scheme1name = Scheme1name;
    this->Scheme1perc = Scheme1Perc;
    this->Scheme2name = Scheme2name;
    this->Scheme2perc = Scheme2Perc;
    this->Scheme3name = Scheme3name;
    this->Scheme3perc = Scheme3Perc;
    this->Scheme4name = Scheme4name;
    this->Scheme4perc = Scheme4Perc;
}

QString Scheme::getScheme1name(){
    return this->Scheme1name;
}

QString Scheme::getScheme2name(){
    return this->Scheme2name;
}
QString Scheme::getScheme3name(){
    return this->Scheme3name;
}
QString Scheme::getScheme4name(){
    return this->Scheme4name;
}
int Scheme::getScheme1perc(){
    return this->Scheme1perc;
}
int Scheme::getScheme2perc(){
    return this->Scheme2perc;
}
int Scheme::getScheme3perc(){
    return this->Scheme3perc;
}
int Scheme::getScheme4perc(){
    return this->Scheme4perc;
}



