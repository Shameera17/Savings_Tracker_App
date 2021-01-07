#include "dashboard.h"
#include "dbgateway.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
        qDebug() << "DB is not connected";
    }

    qry.exec("select isVAULT from USER where USERID = 1");
    qry.next();
    QString result = qry.value(0).toString();
    if(result == "0"){
        qDebug() << result;
        Dashboard w;
        w.show();
        return a.exec();
    }
    else{
        Login l;
        l.show();
        return a.exec();
    }
   if(!qry.exec()){
       qDebug() << "Could get result";
   }
    db.DBdisconnect();

    return a.exec();


}
