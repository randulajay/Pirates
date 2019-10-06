#include "signup.h"
#include "ui_signup.h"

#include<QMessageBox>

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

    this-> setWindowTitle(" S I G N U P ");

    //Check database connection
    loginform conn;
    if(!conn.connOpen())
        ui->label_3->setPixmap(QPixmap(QString::fromUtf8 ( ":/images/Images/wr.png" )));
    else
        ui->label_3->setPixmap(QPixmap(QString::fromUtf8 ( ":/images/Images/ti.png" )));
}

signup::~signup()
{
    delete ui;
}

void signup::on_savesup_clicked()
{
    //add username & password to the database
    loginform conn;
    QString newname, new_password;
    newname=ui->newname->text();
    new_password=ui->newpw->text();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into user_info (username,password) values ('"+newname+"','"+new_password+"')");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("save"),tr("data is save"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }


}

//set exit button
void signup::on_pushButton_clicked()
{
    this->close();
}
