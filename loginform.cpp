#include "loginform.h"
#include "ui_loginform.h"
#include"menubar.h"

loginform::loginform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginform){
    ui->setupUi(this);

    this-> setWindowTitle(" L O G I N ");


    if(!connOpen())
        ui->label_3->setPixmap(QPixmap(QString::fromUtf8 ( ":/images/Images/wr.png" )));
    else
        ui->label_3->setPixmap(QPixmap(QString::fromUtf8 ( ":/images/Images/ti.png" )));
    //setText("connected");
}

loginform::~loginform(){
    delete ui;
}

void loginform::on_pushButton_clicked()
{


    QString username, password;
    username=ui->userid->text();
    password=ui->pw->text();

    if(!connOpen())
    {
        qDebug()<<"Something wend wrong";
        return;
    }

    //Check username&password with database data
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from user_info where username='"+username+"' and password ='"+password+"'");

    if(qry.exec()){
        int count=0;// this will count number of time the exe: the queary
        while (qry.next()){
            count++;
        }
        if(count==1){
            ui->label_3->setText("username and password is correct");
            connClose();
            this->close();

            //if password&username correct connect to the game
            menub =new Menubar(this);
            menub->show();
        }

        if(count>1){
            ui->label_3->setText("Dublicate username password");
        }

        if(count<1){
            ui->label_3->setText("Username or Password is not correct");
        }
    }
}

void loginform::on_pushButton_2_clicked(){
    menub =new Menubar(this);
    menub->show();
}
