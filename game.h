#ifndef GAME_H
#define GAME_H

#include"health.h"
#include"Player.h"
#include"score.h"
#include"gameover.h"


#include<QGraphicsView>
#include<QtWidgets>
#include<QGraphicsScene>

class Game : public QGraphicsView
{
     Q_OBJECT
public:
    Game(QWidget * parent =nullptr);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

private:
    Ui::Gameover *ui;
    Gameover *gameover;

public slots:
    void end();//Conncet end() function to pop-up Gameover ui
    void dolife();//Call to heath hart for the scene

};
#endif // GAME_H
