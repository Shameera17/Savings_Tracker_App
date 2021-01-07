#include "dashboard.h"
#include "ui_dashboard.h"
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QComboBox>
#include <QMessageBox>
#include <QTextLength>
#include "transactioncontroller.h"
#include "accountcontroller.h"
#include "schemecontroller.h"
#include<QPixmap>
Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/images/2086.jpg");
    int w = ui->lblimg->width();
    int h = ui->lblimg->height();
    ui->lblimg->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //Combo box for type and repository
    QStringList list_item, accounttype;
    list_item << "Debit" << "Credit";
    ui->comboBoxType->addItems(list_item);
    accounttype <<"Main Acc"<< "Scheme1" << "Scheme2" << "Scheme3" << "Scheme4";
    ui->comboBoxRepo->addItems(accounttype);

    //loadtransactions
    this->LoadAccountTransaction();
    //load scheme details
    this->LoadSavingPlanDetails();

    //auto load balance
    double bal = DisplayBalance();
    QString ball = QString::number(bal , 'f', 2);
    ui->txtBalance->setText(ball);
}

Dashboard::~Dashboard()
{
    delete ui;
}

//view current balance
double Dashboard::DisplayBalance(){
    DBGateway db;
    QSqlQuery qry;
    double balance;

    if(!db.DBconnect()){
       qDebug()<<"DB is not connected @ fetch current balance";
    }
    balance = qry.exec("select sum(AMOUNT) from ACCTRANSACTION");
    while (qry.next()) {
            balance = qry.value(0).toDouble();
            qDebug() << balance ;
        }
    if(!qry.exec()){
        qDebug()<<"Error in query @ fetch current balance";
    }
    db.DBdisconnect();
    return balance;
}


void Dashboard::on_btnSetScheme_clicked()
{
    QString scheme1 = ui->txtScheme_1->text();
    QString scheme2 = ui->txtScheme_2->text();
    QString scheme3 = ui->txtScheme_3->text();
    QString scheme4 = ui->txtScheme_4->text();

    int percentage1 = ui->txtPerc1->text().toInt();
    int percentage2 = ui->txtPerc2->text().toInt();
    int percentage3 = ui->txtPerc3->text().toInt();
    int percentage4 = ui->txtPerc4->text().toInt();

    int total = percentage1 + percentage2 + percentage3 + percentage4;
    if(!(total > 100)){
        ui->label_22->setText("Set percentages that total upto 100");
    }
    SchemeController schemeController;

}


//fetch main acc bal
void Dashboard::on_btnFetchBal_clicked()
{
    //reload bal
    double bal = DisplayBalance();
    QString ball = QString::number(bal , 'f', 2);
    ui->txtBalance->setText(ball);
}

//click create Transaction
void Dashboard::on_btnCreateTransaction_clicked()
{
    QString Amount = ui->txtAmount->text();
    QString Description = ui->txtDescription->text();
    QString repotype = ui->comboBoxRepo->currentText();
    QString type = ui->comboBoxType->currentText();
    QString date = ui->dateEdit->text();

    if(Amount.isNull() || Description.isNull() ||repotype.isNull()|| type.isNull() || date.isNull()) {
                QMessageBox::critical(this,"Transaction error","Please fill/select all the fields");
        }
    double amount = Amount.toDouble();
    double currentBal = DisplayBalance();

    qDebug() <<amount<<currentBal;

    if(type == "Credit"){
        if(amount > currentBal)
        {
            QMessageBox::critical(this,"Transaction error","Credit request exceed current balance");
        }
    }
    if(type == "Credit" && repotype == "Main Acc"){
        ui->lblStatus_2->setText("Please select a Scheme for Credit Transaction");
    }
    else{
        Transaction transaction(date,Amount,type,Description,repotype);
        TransactionController transController;
        transController.AddTransaction(transaction);
    }

}

//upddate password
void Dashboard::on_pushButton_5_clicked()
{
    QString passcode = ui->txtPasscode->text();
    if(passcode == "" || passcode == "Enter PASSCODE"){
        ui->lblStatus->setText("Invalid input");
    }
    else{
        ui->lblStatus->setText("");
    }

    AccountController accController;
    accController.updatePasscode(passcode);

}

//update Scheme1
void Dashboard::on_schemeEdit1_clicked()
{
    QString schemeName = ui->txtScheme_1->text();
    QString p = ui->txtPerc1->text();
    int perc = ui->txtPerc1->text().toInt();
    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
       qDebug()<<"DB is not connected @ update scheme1";
    }
    if(perc>100 ||p.isNull() ){
        QMessageBox::warning(this,"Input Error","Invlid input");
    }
    else{
        qry.prepare("update SAVINGSCHEME set SAVNAME = ?,PERCENTAGEVALUE = ? where SCHEMEID = ?");
        qry.bindValue(0,schemeName);
        qry.bindValue(1,perc);
        qry.bindValue(2,1);
        if(qry.exec()){
            qDebug()<<"query not executed @ update scheme1";
        }
    }
    db.DBdisconnect();
}

//update Scheme2
void Dashboard::on_schemeEdit2_clicked()
{
    QString schemeName = ui->txtScheme_2->text();
    QString p = ui->txtPerc2->text();
    int perc = ui->txtPerc2->text().toInt();
    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
       qDebug()<<"DB is not connected @ update scheme2";
    }
    if(perc>100 ||p.isNull() ){
        QMessageBox::warning(this,"Input Error","Invlid input");
    }
    else{
        qry.prepare("update SAVINGSCHEME set SAVNAME = ?,PERCENTAGEVALUE = ? where SCHEMEID = ?");
        qry.bindValue(0,schemeName);
        qry.bindValue(1,perc);
        qry.bindValue(2,2);
        if(qry.exec()){
            qDebug()<<"query not executed @ update scheme2";
        }
    }
    db.DBdisconnect();
}
//update Scheme3
void Dashboard::on_schemeEdit3_clicked()
{
    QString schemeName = ui->txtScheme_3->text();
    QString p = ui->txtPerc3->text();
    int perc = ui->txtPerc3->text().toInt();
    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
       qDebug()<<"DB is not connected @ update scheme3";
    }
    if(perc>100 ||p.isNull() ){
        QMessageBox::warning(this,"Input Error","Invlid input");
    }
    else{
        qry.prepare("update SAVINGSCHEME set SAVNAME = ?,PERCENTAGEVALUE = ? where SCHEMEID = ?");
        qry.bindValue(0,schemeName);
        qry.bindValue(1,perc);
        qry.bindValue(2,3);
        if(qry.exec()){
            qDebug()<<"query not executed @ update scheme3";
        }
    }
    db.DBdisconnect();
}

//update Scheme4
void Dashboard::on_schemeEdit4_clicked()
{
    QString schemeName = ui->txtScheme_4->text();
    QString p = ui->txtPerc4->text();
    int perc = ui->txtPerc4->text().toInt();
    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
       qDebug()<<"DB is not connected @ update scheme4";
    }
    if(perc>100 ||p.isNull() ){
        QMessageBox::warning(this,"Input Error","Invlid input");
    }
    else{
        qry.prepare("update SAVINGSCHEME set SAVNAME = ?,PERCENTAGEVALUE = ? where SCHEMEID = ?");
        qry.bindValue(0,schemeName);
        qry.bindValue(1,perc);
        qry.bindValue(2,4);
        if(qry.exec()){
            qDebug()<<"query not executed @ update scheme4";
        }
    }
    db.DBdisconnect();
}
//accidental
void Dashboard::on_comboBoxType_currentIndexChanged(const QString &arg1)
{
 QString ero = arg1;
}

//load Scheme data
void Dashboard::LoadSavingPlanDetails(){
    SchemeController schemecontroller;
    schemecontroller.displaySchemes(ui->tableView_savingsplan);
}
void Dashboard::on_btnLoadsaving_clicked()
{
    this->LoadSavingPlanDetails();
}
//load transaction data
void Dashboard::LoadAccountTransaction(){
    AccountController accController;
    accController.displayAccountbalances(ui->tableView_transactions);
}

void Dashboard::on_btnLoadData_clicked()
{
    this->LoadAccountTransaction();
}

void Dashboard::on_validatepercentages_clicked()
{
    QString scheme1 = ui->txtScheme_1->text();
    QString scheme2 = ui->txtScheme_2->text();
    QString scheme3 = ui->txtScheme_3->text();
    QString scheme4 = ui->txtScheme_4->text();

    int percentage1 = ui->txtPerc1->text().toInt();
    int percentage2 = ui->txtPerc2->text().toInt();
    int percentage3 = ui->txtPerc3->text().toInt();
    int percentage4 = ui->txtPerc4->text().toInt();

    int total = percentage1 + percentage2 + percentage3 + percentage4;
    if(!(total > 100)){
        ui->label_22->setText("Set percentages that total upto 100");
    }
    if(!(total == 100)){
         ui->label_22->setText(" Best practise : Set percentages to total upto 100 ");
    }
    if(total == 100){
        ui->label_22->setText(" AWESOME !! ");
    }
}

//ignore this :)
void Dashboard::on_pushButton_3_clicked()
{

}
void Dashboard::on_btnSetScheme_2_clicked()
{

}
