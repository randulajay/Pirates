#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include<QObject>
#include<QtDebug>
#include<QGraphicsScene>

class Bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
  Bullet ();


public slots:

  //Create function to call move() to move bullets
  void move();
};

#endif // BULLET_H
