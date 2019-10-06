#include"enemy.h"
#include"life.h"
#include"game.h"
#include"bigenemy.h"
#include"Player.h"
#include"bullet.h"

#include<QKeyEvent>
#include<QGraphicsScene>

extern Game * game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem (parent)//----->Player's graphics settings
{
    //Add bullet sound
    bullectsound=new QMediaPlayer();
    bullectsound->setMedia(QUrl("qrc:/music/Audio/p_shoot.mp3"));

    //Add Players's Ship graphics
    setPixmap(QPixmap(":/images/Images/Ship.png"));

}

void Player::keyPressEvent(QKeyEvent * event)//---------------------------->Button click events
{

    //move palyer to the Left
    if(event->key() == Qt::Key_Left)
    {
        //prevent the player is going to the out side of the screen
        if(pos().x()>0)
            setPos(x()-10,y());
    }


    //move palyer to the Right
    else if (event->key()==Qt::Key_Right)
    {
        //prevent the player is going to the out side of the screen
        if(pos().x()+100<800)
            setPos(x()+10,y());
    }


    //Shoot from the spacebar
    else if(event->key()==Qt::Key_Space)
    {
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+18,y());
        scene()->addItem(bullet);

        //Create Fire sound
        if(bullectsound->state() == QMediaPlayer::PlayingState)
        {
            bullectsound->setPosition(0);
        }
        else if(bullectsound->state() == QMediaPlayer::StoppedState)
            bullectsound->play();

    }

}



void Player::spawn()
{
    //Add enemies
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player:: spawnlife()
{
    //Add harts
    Life * life = new Life();
    scene()->addItem(life);
}

void Player::spawnbigenemy()
{
    //Add big ships
    Bigenemy * bigenemy = new Bigenemy();
    scene()->addItem(bigenemy);
}
