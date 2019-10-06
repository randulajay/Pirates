#include "health.h"
#include<QFont>


Health::Health(QGraphicsItem *parent) : QGraphicsTextItem (parent){

        health=3;
        //draw  the text "health=3"
        setPlainText(QString("HEALTH :  ")+QString::number(health));
        setDefaultTextColor(Qt::red);//Colour
        setFont(QFont("Monospace",20,QFont::Bold));//Font
}

void Health::decrease(){
    health--;
    setPlainText(QString("HEALTH :  ")+QString::number(health));
    if(health==0){
       //Display gameover.ui
       emit dead();
    }

    else if (health<3){
            emit getlife();
        }
}

void Health::increase(){
    if(health<3){
        health++;
        setPlainText(QString("HEALTH :  ")+QString::number(health));
    }
}

int Health::getHealth(){
     return health;
}


