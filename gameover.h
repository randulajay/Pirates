#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

#include"score.h"

namespace Ui {
class Gameover;
}

class Gameover : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gameover(QWidget *parent = nullptr);
    ~Gameover();

private slots:
    void on_button_cancel_clicked();

    void on_button_ok_clicked();

    void on_save_clicked();

private:
    Ui::Gameover *ui;
};

#endif // GAMEOVER_H
