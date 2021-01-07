#include "dbgateway.h"

DBGateway::DBGateway()
{
    //db path
    path = QDir::homePath() + "/savingTracker.db";
    //set SQLITE
    db = QSqlDatabase::addDatabase("QSQLITE");
    //add path
    db.setDatabaseName(path);
    qDebug() << "Database is located @ " << path;
}

bool DBGateway::DBconnect(){
    if(db.open()){
        return true;
    }else{
        return false;
    }
}


void DBGateway::DBdisconnect(){
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

QSqlDatabase DBGateway::getDB(){
    return db;
}
