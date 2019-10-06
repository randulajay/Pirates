#ifndef SCORECARD_H
#define SCORECARD_H

#include"loginform.h"

#include <QMainWindow>

namespace Ui {
class scoreCard;
}

class scoreCard : public QMainWindow{
    Q_OBJECT

public:

    explicit scoreCard(QWidget *parent = nullptr);
    ~scoreCard();

private slots:

    void on_load_clicked();

    void on_pushButton_clicked();

private:
    Ui::scoreCard *ui;
};

#endif // SCORECARD_H
