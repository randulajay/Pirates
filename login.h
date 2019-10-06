#ifndef LOGIN_H
#define LOGIN_H

#include "menubar.h"
#include"loginform.h"
#include"signup.h"
#include"scorecard.h"
#include"about.h"

#include<QTimer>
#include <QMainWindow>

namespace Ui {
class Login;
}
class QMediaPlayer;

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_login_clicked();

    void on_sign_up_clicked();

    void on_pushButton_4_clicked();

    void on_about_clicked();

    void clock();

    void on_pushButton_2_clicked();

    void on_exit_clicked();

private:
    Ui::Login *ui;
    Menubar *start1;
    loginform *logf;
    signup * sign;
    scoreCard * score;
    About * about;
    QTimer * timer;
    QMediaPlayer * audio;
};

#endif // LOGIN_H
