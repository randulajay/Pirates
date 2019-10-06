#include"menubar.h"
#include"ui_menubar.h"
#include"game.h"
#include"loginform.h"
#include"ui_loginform.h"

Game * game; //Globle variable

Menubar::Menubar(QWidget *parent):QMainWindow(parent),ui(new Ui::Menubar)
{
    ui->setupUi(this);
    this-> setWindowTitle(" P I R A T E S ");

    //Set Game to the central area of main wondow
    game=new Game(this);
    setCentralWidget(game);
}

Menubar::~Menubar()
{
    delete ui;
}

// Set exit menu of menubar
void Menubar::on_actionExit_triggered()
{
    QApplication::exit();
}

//Set new game menu of menubar
void Menubar::on_actionNew_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
