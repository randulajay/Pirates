#include"life.h"
#include"enemy.h"
#include"game.h"
#include"health.h"
#include<QGraphicsPixmapItem>
#include<QObject>
#include<QtDebug>
#include<QTimer>
#include<stdlib.h>


extern Game * game;
Life::Life(){
    //reqest for a new life
    int numberx = rand() % 700;
    setPos(numberx,0);

    setPixmap(QPixmap(":/images/Images/life.png"));

    QTimer * timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Life::move(){
    //Move Health Hart down
    {
        setPos(x(),y()+10);

        //delete Hart from memory after past the screen border
        if(pos().y()>600)
        {
            scene()->removeItem(this);
            delete this;          
        }
    }
}
