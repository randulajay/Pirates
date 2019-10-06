#ifndef SIGNUP_H
#define SIGNUP_H
#include"loginform.h"

#include <QMainWindow>

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    loginform conn;
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:

    void on_savesup_clicked();

    void on_pushButton_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
