#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsPixmapItem>
#include<QObject>
#include<QtDebug>
#include<QGraphicsScene>

class Life:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Life();

public slots:

  void move();

private:

};

#endif // LIFE_H
