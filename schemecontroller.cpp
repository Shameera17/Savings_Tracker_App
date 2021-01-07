#include "schemecontroller.h"

SchemeController::SchemeController()
{

}
void SchemeController::updateSchemes(Scheme scheme){
QString name1 = scheme.getScheme1name();
QString name2 = scheme.getScheme2name();
QString name3 = scheme.getScheme3name();
QString name4 = scheme.getScheme4name();

}


void SchemeController::displaySchemes(QTableView *tbl){
    DBGateway db;
    QSqlQueryModel *model;
    QSqlQuery *qry;

    model = new QSqlQueryModel();
    qry = new QSqlQuery(db.getDB());

    if(!db.DBconnect()){
        qDebug()<<"connection failed @ display SCHEME controller";
    }

    qry->prepare("SELECT SAVNAME, PERCENTAGEVALUE, AMOUNT FROM SAVINGSCHEME");

    if(!qry->exec()){
        qDebug()<<"Scheme loading query not executed";
    }
    model->setQuery(*qry);
    tbl->setModel(model);
    db.DBdisconnect();
}
