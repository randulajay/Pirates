#ifndef LOGINFORM_H
#define LOGINFORM_H
#include"menubar.h"
#include<QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class loginform;
}

class loginform : public QMainWindow
{
    Q_OBJECT

public:
    //name database as battleship
    QSqlDatabase battleship;

    //set connection close function
    void connClose()
    {
        battleship.close();
        battleship.removeDatabase(QSqlDatabase::defaultConnection);
    }

    //connection close function
    bool connOpen(){
    battleship=QSqlDatabase::addDatabase("QSQLITE");
    battleship.setDatabaseName("qrc:/Database/Database/SQLITE.db");

    if(!battleship.open()){
        return false;
    }
    else{
        return true;
    }
}

    explicit loginform(QWidget *parent = nullptr);
    ~loginform();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::loginform *ui;
    Menubar * menub;
};

#endif // LOGINFORM_H
