#include "scorecard.h"
#include "ui_scorecard.h"


scoreCard::scoreCard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scoreCard)
{
    ui->setupUi(this);
    this-> setWindowTitle(" S C O R E ");

    //chech connection
    loginform conn;
    if(!conn.connOpen())
        ui->label1->setPixmap(QPixmap(QString::fromUtf8 ( ":/images/Images/wr.png" )));
    else
        ui->label1->setPixmap(QPixmap(QString::fromUtf8 ( ":/images/Images/ti.png" )));
}


scoreCard::~scoreCard()
{
    delete ui;
}

//set load button
void scoreCard::on_load_clicked()
{
    loginform conn;
    QSqlQueryModel * modal1= new QSqlQueryModel();

    //Open database connection and get data and display
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.battleship);

    qry->prepare("select username,score from user_info");

    qry->exec();
    modal1->setQuery(*qry);
    ui->tableView->setModel(modal1);

    //connection close
    conn.connClose();
    qDebug()<<(modal1->rowCount());

}

//set exit button
void scoreCard::on_pushButton_clicked()
{
    this->close();
}
