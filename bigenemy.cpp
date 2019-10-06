#include "bigenemy.h"
#include<game.h>
#include<QTimer>

extern Game * game;
Bigenemy::Bigenemy(): QObject() , QGraphicsPixmapItem ()
{
    //Set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //Add big enemy graphics to the scene
    setPixmap(QPixmap(":/images/Images/bigenemy.png"));

    //Conncect Bigenemies
    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

//move big enemy ship to down
void Bigenemy::move()
{
     setPos(x(),y()+15);

     //Delete big ship enemy after passed the border
     if(pos().y()>600)
    {        
         //Decrease the health after passed the border one by one
         game->health->decrease();

         //Delete big enemy ship crash becatuse its wasting memory
         scene()->removeItem(this);
         delete this;
     }
}


