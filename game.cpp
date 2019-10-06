#include "game.h"
#include"Player.h"
#include"enemy.h"
#include"score.h"
#include"gameover.h"
#include"Player.h"
#include"life.h"


#include<QFont>
#include<QTimer>
#include<QGraphicsTextItem>
#include<QGraphicsScene>
#include<QMediaPlayer>
#include<QImage>

Game::Game(QWidget * parent)
{
    //Create a Scene
    QGraphicsScene * scene= new QGraphicsScene();

    //Set screen ratio 800*600
    scene->setSceneRect(0,0,800,600);

    //Set background image
    setBackgroundBrush(QBrush((QImage(":/images/Images/back.png"))));

    setScene(scene);

    //avoiding unnecessary screen changers
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Set default Siza to the View
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Create a Player
    player= new Player();
    player->setPos(400,500);

    //Make Player fosusble
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Make Player fosusble
    scene->addItem(player);//Add Player to the scene

    //spawn enemies
    QTimer * timer =new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //spawn big enemy ships
    QTimer * time =new QTimer();
    QObject::connect(time,SIGNAL(timeout()),player,SLOT(spawnbigenemy()));
    time->start(10000);

    //Set a position to display score
    score= new Score();
    score->setPos(score->x()+220,score->y());
    scene->addItem(score);

    //set health to the screen
    health= new Health();
    health->setPos(health->x()+420,health->y());
    scene->addItem(health);

    //Add background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/Audio/gamebg.mp3"));
    music->play();


    connect( health, SIGNAL(dead()), this, SLOT(end()) );//Connect dead() slot with end to gameover
    connect( health,SIGNAL(getlife()), this, SLOT(dolife()));//Connect to get harts



}

void Game::end()
{

    this->close();


    //Call for gameOver.ui
    gameover = new Gameover(this);
    gameover->show();
}

void Game::dolife()
{
    //Conncet with swapn function
    QTimer * time =new QTimer();
    QObject::connect(time,SIGNAL(timeout()),player,SLOT(spawnlife()));
    time->start(10000);
}


