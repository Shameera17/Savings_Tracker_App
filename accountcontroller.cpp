#include "accountcontroller.h"

AccountController::AccountController()
{

}

void AccountController::updatePasscode(Account account){
    QString passcode = account.getPasscode();

    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
        qDebug() << "DB Connection failed @ account controller";
    }

    qry.prepare("update USER set isVault = ? , PASSCODE = ? where USERID = 1;");
    qry.bindValue(0, true);
    qry.bindValue(1, passcode);

    if(!qry.exec()){
        qDebug() << "Passcode is unable to update";
    }

    db.DBdisconnect();
}

void AccountController::displayAccountbalances(QTableView *tbl){
    DBGateway db;
    QSqlQueryModel *model;
    QSqlQuery *qry;

    model = new QSqlQueryModel();
    qry = new QSqlQuery(db.getDB());

    if(!db.DBconnect()){
        qDebug()<<"connection failed @ display account controller";
    }

    qry->prepare("SELECT DATE, AMOUNT, TYPE, DESCRIPTION FROM ACCTRANSACTION");

    if(!qry->exec()){
        qDebug()<<"Account loading query not executed";
    }

    model->setQuery(*qry);
    tbl->setModel(model);
    db.DBdisconnect();
}
