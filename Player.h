#ifndef PLAYER_H
#define PLAYER_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QMediaPlayer>
#include<QGraphicsItem>


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    Player(QGraphicsItem * parent=0);

public slots:
    void spawn();//spawn enemies
    void spawnlife();//spawn harts
    void spawnbigenemy();// spawn big enemies ships

private: 
    QMediaPlayer * bullectsound;
};

#endif // PLAYER_H
