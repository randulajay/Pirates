#include"bullet.h"
#include"enemy.h"
#include"game.h"
#include"life.h"
#include"bigenemy.h"
#include<QTimer>

extern Game * game;//Call the globle class Game
Bullet::Bullet() : QObject() , QGraphicsPixmapItem ()
{
     //Graphic fire.png image replace to the bullet
     setPixmap(QPixmap(":/images/Images/fire.png"));

     //Set Time to move down to bullets
     QTimer * timer =new QTimer();
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     timer->start(50);
}

void Bullet::move()
{
    //If bullet collides  with enemy ,destroy both
    QList < QGraphicsItem *> colliding_items = collidingItems();

    //If one of a collides  item is an enemy destroy both
    for(int i=0,n=colliding_items.size(); i<n;++i)

        //Check whether the colluding item is an enemy
        if(typeid (*(colliding_items[i]))==typeid (Enemy))
        {
            //If the collides  item is an enemy increase the score
            game->score->increase();

            //And remove both from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Delete
            delete colliding_items[i];
            delete this;
            return;

        }

        //Check whether the collides item is a big enemy ship
        else if (typeid (*(colliding_items[i]))==typeid (Bigenemy))
        {
            //If collides  iterm is an enemy increase the score
            game->score->increase2();

            //And remove both from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Delete both
            delete colliding_items[i];
            delete this;
            return;
        }

        //Check whether the collides iterm is a Life
        else if (typeid (*(colliding_items[i]))==typeid (Life))
        {
            //Increase the score if it's Life hart
            game->health->increase();

            //And remove both from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }

        //Move bullet down
        setPos(x(),y()-10);

        if (pos().y() < 0)//If the bullet cross the screen border destroy it
        {
            scene()->removeItem(this);
            delete this;//Delete fire cash becatuse its wasting memory
        }
}


