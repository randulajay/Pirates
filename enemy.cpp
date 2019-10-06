#include "enemy.h"
#include<stdlib.h>
#include"game.h"
#include<QTimer>

extern Game * game;
Enemy::Enemy() : QObject() , QGraphicsPixmapItem ()
{
    //Set random x position
   int random_number = rand() % 700;
   setPos(random_number,0);

   //Draw enemies
   setPixmap(QPixmap(":/images/Images/enemy.png"));

   //Conncect bullets
   QTimer * timer =new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
   timer->start(50);

}

void Enemy::move()
{
    //Move enemy to the down
     setPos(x(),y()+5);

     //Delete and Remove
     if(pos().y()>600)
     {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
     }
}
