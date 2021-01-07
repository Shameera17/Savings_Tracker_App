#include "transactioncontroller.h"

TransactionController::TransactionController()
{

}


void TransactionController::storeSavingsSeparately(QString type, double amount, int schemeid){
   double Amount = amount;
   QString Type = type;
   QString id = QString::number(schemeid);
   double newbal = 0.0;
   double balance;
    DBGateway db;
    QSqlQuery qry;



    if(!db.DBconnect()){
            qDebug() << "DB connection failed to open the updating scheme separately  @ Transaction Controller";
        }

    //get balance

    balance = qry.exec("select AMOUNT from SAVINGSCHEME where SCHEMEID = '"+id+"' ");
//    qry.bindValue(0,id);
    while (qry.next()) {
            balance = qry.value(0).toDouble();
            qDebug() << balance ;
        }

    if(Type == "Debit"){
        newbal = balance + Amount;
    }else if(Type == "Credit"){
        newbal = balance - Amount;
    }


    if(!qry.exec()){
        qDebug() <<"balance fetch error(store savings separately) @ transactionController";
    }


    //update balance
    qry.prepare("update SAVINGSCHEME set AMOUNT = ?  where SCHEMEID = ?");
    qry.bindValue(0,newbal);
    qry.bindValue(1,id);

    if(!qry.exec()){
        qDebug() <<"balance update balance error(store savings separately) @ transactionController";
    }

    db.DBdisconnect();
}

void TransactionController::storeSavings(double amount)
{
    double Amount = amount;
    DBGateway db;
    QSqlQuery qry;
    std::vector<int> percentages;
    std::vector<double>amounts;

    int p1,p2,p3,p4;
    double b1,b2,b3,b4;
    double s1,s2,s3,s4;

    if(!db.DBconnect()){
            qDebug() << "DB connection failed to open the updating schemes @ Transaction Controller";
        }

    qry.prepare("select PERCENTAGEVALUE from SAVINGSCHEME");
    if(!qry.exec()){
        qDebug() <<"percentage fetch error(store savings) @ transactionController";
    }
    while (qry.next()) {
           percentages.push_back(qry.value(0).toInt());
//           amounts.push_back(qry.value(1).toDouble());
        }

        p1 = percentages.at(0);
        p2 = percentages.at(1);
        p3 = percentages.at(2);
        p4 = percentages.at(3);


    qry.clear();

    qry.prepare("select AMOUNT from SAVINGSCHEME");
    if(!qry.exec()){
          qDebug() <<"percentage amount error(store savings) @ transactionController";
      }
    while (qry.next()) {
            amounts.push_back(qry.value(0).toDouble());
        }
    b1 = amounts.at(0);
    b2 = amounts.at(1);
    b3 = amounts.at(2);
    b4 = amounts.at(3);

    qry.clear();

    qDebug()<<b1<<b2<<b3<<b4<<"amounts-1";
    qDebug()<<p1<<p2<<p3<<p4<<"percentages-1";
    //cal new amounts to add
        s1 = b1 + Amount*((double)p1/100.00);
        s2 = b2 + Amount*((double)p2/100.00);
        s3 = b3 + Amount*((double)p3/100.00);
        s4 = b4 + Amount*((double)p4/100.00);

        qDebug()<<s1<<s2<<s3<<s4<<"New amount";
        qDebug()<<b1<<b2<<b3<<b4<<"amounts-2";
        qDebug()<<p1<<p2<<p3<<p4<<"percentages-2";

        qry.prepare("update SAVINGSCHEME set amount = ? where SCHEMEID = ?");
        qry.bindValue(0,s1);
        qry.bindValue(1,1);
        if(!qry.exec()){
            qDebug() <<"amount update scheme1(store savings) @ transactionController";
        }
        qry.clear();

        qry.prepare("update SAVINGSCHEME set amount = ? where SCHEMEID = ?");
        qry.bindValue(0,s2);
        qry.bindValue(1,2);
        if(!qry.exec()){
            qDebug() <<"amount update scheme2(store savings) @ transactionController";
        }
        qry.clear();

        qry.prepare("update SAVINGSCHEME set amount = ? where SCHEMEID = ?");
        qry.bindValue(0,s3);
        qry.bindValue(1,3);
        if(!qry.exec()){
            qDebug() <<"amount update scheme3(store savings) @ transactionController";
        }
        qry.clear();

        qry.prepare("update SAVINGSCHEME set amount = ? where SCHEMEID = ?");
        qry.bindValue(0,s4);
        qry.bindValue(1,4);
        if(!qry.exec()){
            qDebug() <<"amount update scheme4(store savings) @ transactionController";
        }
        qry.clear();

        db.DBdisconnect();

}



void TransactionController::AddTransaction(Transaction transaction){

        QString transDate = transaction.getDate();
        QString transDescription = transaction.getDescription();
        QString transAmount = transaction.getAmount();
        QString transType = transaction.getType();
        QString transRepo = transaction.getRepo();

        DBGateway db;
        QSqlQuery qry;

        if(!db.DBconnect()){
                qDebug() << "DB connection failed to open the database @ParseTransaction";
            }
        double Amount = transAmount.toDouble();


        int transRepoint;

        if(transRepo == "Main Acc"){
            transRepoint = 1;
        }
        else if(transRepo == "Scheme1"){
            transRepoint = 2;
        }
        else if(transRepo == "Scheme2"){
            transRepoint = 3;
        }
        else if(transRepo == "Scheme3"){
            transRepoint = 4;
        }
        else if(transRepo == "Scheme4"){
            transRepoint = 5;
        }

        if(transType == "Credit"){

            qry.prepare("insert into ACCTRANSACTION(DATE, AMOUNT, TYPE, DESCRIPTION,ACCID) values (?,?,?,?,?)");
            qry.bindValue(0, transDate);
            qry.bindValue(1, Amount);
            qry.bindValue(2, transType);
            qry.bindValue(3, transDescription);
            qry.bindValue(4, 1);

            if(!qry.exec()){
                qDebug() << "Transaction could't be added :( ";
            }
            qry.clear();
            switch(transRepoint){
            case 2:{
                storeSavingsSeparately(transType,Amount,1);
                break;
            }
            case 3:{
                storeSavingsSeparately(transType,Amount,2);
                break;
            }
            case 4:{
                storeSavingsSeparately(transType,Amount,3);
                break;
            }

            case 5:{
                storeSavingsSeparately(transType,Amount,4);
                break;
            }
            }
         }
        else if(transType == "Debit"){
            qry.prepare("insert into ACCTRANSACTION(DATE, AMOUNT, TYPE, DESCRIPTION,ACCID) values (?,?,?,?,?)");
                qry.bindValue(0, transDate);
                qry.bindValue(1, Amount);
                qry.bindValue(2, transType);
                qry.bindValue(3, transDescription);
                qry.bindValue(4, 1);

                if(!qry.exec()){
                    qDebug() << "Transaction could't be added :( ";
                }

                switch(transRepoint){
                case 1 :{
                    storeSavings(Amount);
                    break;
                }
                case 2:{
                    storeSavingsSeparately(transType,Amount,1);
                    break;
                }
                case 3:{
                    storeSavingsSeparately(transType,Amount,2);
                    break;
                }
                case 4:{
                    storeSavingsSeparately(transType,Amount,3);
                    break;
                }
                case 5:{
                    storeSavingsSeparately(transType,Amount,4);
                    break;
                }
                }
        }



        db.DBdisconnect();
}




