#include "score.h"

#include<QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem (parent)
{
    score = 0;//Initialize score "score : 0"

    //Display score on the game window
    setPlainText(QString("SCORE :  ")+QString::number(score));
    setDefaultTextColor(Qt::yellow);//Colour
    setFont(QFont("Monospace",20,QFont::Bold));//Font



}

void Score::increase()
{
    score++;
    setPlainText(QString("SCORE :  ")+QString::number(score));
}

void Score::increase2()
{
    score+=5;
    setPlainText(QString("SCORE :  ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}


