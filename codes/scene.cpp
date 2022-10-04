#include "scene.h"
#include <iostream>

Scene::Scene(QObject *parent)
{
    btnMode = 0;
    card1_num = 0;
    card2_num = 0;
    enemy_num = 0;
}

void Scene::gameIni(int x)
{
    //Tower
    Tower *TowerLeft;
    TowerLeft = new Tower(2000, 100, 200, 20, 1);
    QPixmap tower1;
    tower1.load(":/image/img/castleL1.gif");
    tower1 = tower1.scaled(250,450,Qt::KeepAspectRatio);
    TowerLeft -> setPixmap(tower1);
    TowerLeft -> setPos(50,81);
    addItem(TowerLeft);

    Tower *TowerRight;A
    TowerRight = new Tower(2000, 100, 200, 20, 1);
    QPixmap tower2;
    tower2.load(":/image/img/castleR1.gif");
    tower2 = tower2.scaled(250,450,Qt::KeepAspectRatio);
    TowerRight -> setPixmap(tower2);
    TowerRight -> setPos(1160,79);
    addItem(TowerRight);

    Btn *btnTowerAtk;
    btnTowerAtk = new Btn;
    QPixmap towerBtn;
    towerBtn.load(":/image/img/atkbtn.gif");
    towerBtn = towerBtn.scaled(120, 120, Qt::KeepAspectRatio);
    btnTowerAtk -> setPixmap(towerBtn);
    btnTowerAtk -> setPos(700, 510);
    addItem(btnTowerAtk);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /*if(btnMode == 1)
     {
     
      }
      if(event -> scenePos().x() > btnTowerAtk -> pos().x() && event -> scenePos().x() <= (btnTowerAtk -> pos().x())+120)
            {
                if(event -> scenePos().y() > btnTowerAtk -> pos().y() && event -> scenePos().y() <= (btnTowerAtk -> pos().y())+120)
                {
                    
                
                }
            }*/
}

void Scene::Judge()
{

}


void Scene::minionIni()
{

}

void Scene::enemyIni()
{
    QPixmap enemy1; enemy1.load(":/image/img/enemy.gif");   enemy1 = enemy1.scaled(120,120,Qt::KeepAspectRatio);
    QPixmap enemy2; enemy2.load(":/image/img/enemy.gif");   enemy2 = enemy2.scaled(120,120,Qt::KeepAspectRatio);
    QPixmap enemy3; enemy3.load(":/image/img/enemy.gif");   enemy3 = enemy3.scaled(120,120,Qt::KeepAspectRatio);
    QPixmap enemy4; enemy4.load(":/image/img/enemy.gif");   enemy4 = enemy4.scaled(120,120,Qt::KeepAspectRatio);

    Unit *Uenemy1;  Uenemy1 = new Unit(600, 100, 10, 10, 2);    Uenemy1 -> setPixmap(enemy1);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy2;  Uenemy2 = new Unit(600, 100, 10, 10, 2);    Uenemy2 -> setPixmap(enemy1);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy3;  Uenemy3 = new Unit(600, 100, 10, 10, 2);    Uenemy3 -> setPixmap(enemy1);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy4;  Uenemy4 = new Unit(600, 100, 10, 10, 2);    Uenemy4 -> setPixmap(enemy2);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy5;  Uenemy5 = new Unit(600, 100, 10, 10, 2);    Uenemy5 -> setPixmap(enemy2);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy6;  Uenemy6 = new Unit(600, 100, 10, 10, 2);    Uenemy6 -> setPixmap(enemy3);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy7;  Uenemy7 = new Unit(600, 100, 10, 10, 2);    Uenemy7 -> setPixmap(enemy3);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy8;  Uenemy8 = new Unit(600, 100, 10, 10, 2);    Uenemy8 -> setPixmap(enemy4);    Uenemy1 -> setPos(1110,422);
    Unit *Uenemy9;  Uenemy9 = new Unit(600, 100, 10, 10, 2);    Uenemy9 -> setPixmap(enemy4);    Uenemy1 -> setPos(1110,422);
}

void Scene::minionLaunch(int y)
{
    Unit *Uminion1;
    Uminion1 = new Unit(10,10,10,10,1);
    QPixmap minion1;
    if(y == 1)minion1.load(":/image/img/minion1.gif");
    else if(y == 2)minion1.load(":/image/img/minion2.gif");
    else if(y == 3)minion1.load(":/image/img/minion3.gif");
    else if(y == 4)minion1.load(":/image/img/minion4.gif");
    else if(y == 5)minion1.load(":/image/img/minion5.gif");
    else if(y == 6)minion1.load(":/image/img/minion6.gif");
    else if(y == 7)minion1.load(":/image/img/minion7.gif");
    else if(y == 8)minion1.load(":/image/img/minion8.gif");
    else minion1.load(":/image/img/icon.gif");
    minion1 = minion1.scaled(120,120,Qt::KeepAspectRatio);
    Uminion1 -> setPixmap(minion1);
    Uminion1 -> setPos(320,422);
    Uminion1 -> connect(this, SIGNAL(oneSecond()), Uminion1, SLOT(active()));
    addItem(Uminion1);

}

void Scene::enemyLaunch()
{
    qsrand(time(NULL));
    int x = qrand()% 9 + 1;

    if(enemy_num < 9){
        if(x == 1)
    }
    Uenemy1 -> connect(this, SIGNAL(oneSecond()), Uenemy1, SLOT(active()));

        addItem(Uenemy1);



}

void Scene::countdown()
{
    emit oneSecond();
}

void Scene::gameFin()
{

}

