#include "gameover.h"
#include "ui_gameover.h"
#include"score.h"
#include"loginform.h"
#include<QMessageBox>

Gameover::Gameover(QWidget *parent) : QMainWindow(parent), ui(new Ui::Gameover){
    ui->setupUi(this);
    this-> setWindowTitle(" G A M E O V R ");
}

Gameover::~Gameover(){
    delete ui;
}

//No button click event
void Gameover::on_button_cancel_clicked(){
    //Quit Game
    qApp->quit();
}

//Yes button click event
void Gameover::on_button_ok_clicked(){
    //restart the Game
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


void Gameover::on_save_clicked(){
    //check database connection
    loginform conn;
    QString newname, score;
    newname=ui->p_name->text();
    score=ui->p_score->text();

    if(!conn.connOpen())
    {
        qDebug()<<"faild to open databse";
        return;
    }

    //set connection to update table
    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("update user_info set score='"+score+"' where username='"+newname+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("save"),tr("saved"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}
