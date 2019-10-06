#include "about.h"
#include "ui_about.h"
#include"login.h"
#include<QDesktopServices>
#include<QUrl>
#include<QMessageBox>

About::About(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this-> setWindowTitle(" A B O U T ");
}

About::~About()
{
    delete ui;
}

//set Facebook URL to the QpushButton
void About::on_facebook_clicked()
{
    QString link="https://www.facebook.com/randula.jayarathna96";
    QDesktopServices::openUrl(QUrl(link));
}

//set Linkedin URL to the QpushButton
void About::on_linkedin_clicked()
{
    QString link="https://www.linkedin.com/in/randula-jayarathna-67963b117";
    QDesktopServices::openUrl(QUrl(link));
}

//set Github URL to the QpushButton
void About::on_github_clicked()
{
    QString link="https://github.com/krandula";
    QDesktopServices::openUrl(QUrl(link));
}

//Set exit button to close current window
void About::on_exit_clicked()
{
    this->close();
}

//Set Qpushbutton for display name as QMessage
void About::on_pushButton_clicked()
{
    QMessageBox::critical(this,tr("about"),tr(" ⚔ Randula Jayarathna ⚔ "));
}
