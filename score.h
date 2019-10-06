#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>


class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent=0);
    void increase();//score increasing by 1 point
    void increase2();//score increasing by 5 point
    int getScore();

private:
    int score;
};

#endif // SCORE_H
