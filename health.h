#ifndef HEALTH_H
#define HEALTH_H

#include<QGraphicsTextItem>

class Health:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health(QGraphicsItem * parent=0);

    void decrease();//After enemies past the border
    void increase();//After shoot to the health-hart
    int getHealth();//To return Health


signals:
    void dead();
    void getlife();

private:
    int health;

};

#endif // HEALTH_H
