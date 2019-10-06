#ifndef BIGENEMY_H
#define BIGENEMY_H
#include <QGraphicsPixmapItem>
#include<QObject>
#include<QtDebug>
#include<QGraphicsScene>

class Bigenemy:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bigenemy();

    //Create function call move() to move big ships
public slots:
    void move();
};

#endif // BIGENEMY_H
