#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QtDebug>
#include<QGraphicsScene>

class Enemy:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
  Enemy ();

public slots:

  //Create function call move() regular enemy ships
  void move();


};
#endif // ENEMY_H
