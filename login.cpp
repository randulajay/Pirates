#include "login.h"
#include "ui_login.h"
#include "menubar.h"
#include"loginform.h"
#include"signup.h"
#include"scorecard.h"
#include"about.h"
#include<QApplication>
#include<QDebug>
#include<QTimer>
#include<QDateTime>
#include<QMediaPlayer>
#include<QFileDialog>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login){
    ui->setupUi(this);
    this-> setWindowTitle(" P I R A T E S ");
    //set timer
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(clock()));
    timer->start(1000);

    //Add music
    audio = new QMediaPlayer(this);
    audio->setMedia(QUrl("qrc:/music/Audio/bg.mp3"));
    audio->play();
}

Login::~Login(){
    delete ui;
}


//set play/login button
void Login::on_login_clicked(){
    hide();
    audio->stop();
    logf =new loginform(this);
    logf->show();
}


//set signup button
void Login::on_sign_up_clicked(){
    sign =new signup(this);
    sign->show();
}


//set score-card button
void Login::on_pushButton_4_clicked(){
    score =new scoreCard(this);
    score->show();
}


//set about button
void Login::on_about_clicked(){
    about =new About(this);
    about->show();
}


//seet clock
void Login::clock(){
    QTime time= QTime::currentTime();
    QString cl=time.toString("hh : mm : ss");
    if((time.second() % 2 )== 0)
    {
        cl[3]=' ';
        cl[8]=' ';
    }
    ui->label1->setText(cl);
}


//set mute button
void Login::on_pushButton_2_clicked(){
    if(ui->pushButton_2->text()=="Mute")
    {
        audio->setMuted(true);
        ui->pushButton_2->setText("Unmute");
    }
    else
    {
        audio->setMuted(false);
        ui->pushButton_2->setText("Mute");
    }
}


//set exit button
void Login::on_exit_clicked(){
   qApp->quit();
}
