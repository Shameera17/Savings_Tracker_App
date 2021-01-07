#include "login.h"
#include "ui_login.h"
#include<QPixmap>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/images/2086.jpg");
    int w = ui->lblimage->width();
    int h = ui->lblimage->height();
    ui->lblimage->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    QString pwdInput;
    pwdInput = ui->txtPasscode->text();

    DBGateway db;
    QSqlQuery qry;

    if(!db.DBconnect()){
        qDebug()<< "DB not connected";
    }

    qry.prepare("select * from USER where PASSCODE = '"+pwdInput+"' ");

    if(qry.exec())
    {
        int count = 0;
        while(qry.next()){
            count++;
        }
        if(count==1)
        {
            this->hide();
            dashboard = new Dashboard(this);
            dashboard->show();

            db.DBdisconnect();
        }
        if(count<1)
            ui->lblError->setText(" Incorrect passcode - try again");
    }
    if(!qry.exec()){
        qDebug() << "Query execution unsuccessful @ login";
    }

    db.DBdisconnect();

}
