#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>

namespace Ui {
class About;
}

class About : public QMainWindow
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private slots:

    void on_facebook_clicked();

    void on_linkedin_clicked();

    void on_github_clicked();

    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
