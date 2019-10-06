#include"game.h"
#include"login.h"

#include<QApplication>
#include<QSplashScreen>
#include<QTime>
#include<QMainWindow>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //Set image icon
    a.setWindowIcon(QIcon(":/images/Images/captain.png"));

    //Set Splash Screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/Images/captain.png"));
    splash->show();



    Login *log = new Login();
    log->show();

    QTimer::singleShot(3000,splash,SLOT(close()));//Splash screen close
    QTimer::singleShot(3000,log,SLOT(show()));//After the Menubar class will run

    return a.exec();
}
/*
 * basic knoledge about c++ (points and memorny management)
 * topics
 * -QGraphicscene
 * -QgraphicItem
 * -QGraphocItem(QGraphic rectitem)
 * -QGraphicView
 * -events(QPress&QKeyEvent)
 * -Eevnt Propogration System
 * -Qdebug


03.
-QTImer
-SIgnals and slots(conncet function)
-Qobject and Qobject macro


04.
-QgraphicsScenr's secncerect
-Qgraphicview's senceRect
QgraphicsSence's senceRect
QgraphicsView codrdinate vs QgraphicsSence cordinates vs QgraphicItem cordinates

05.
-colldingItems()
-Qtimer and coodinate System

06.
-parents
-QgraphicsTextIterm, setplains

07.
-resource files
QmediaPlayer, setmedia(),Qurl,play()

08.
-QGRaphicsmapItem
-QPixmap
-Qimage

*/


