#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QLabel>
#include <QString>
#include "tower.h"
#include "unit.h"
#include "btn.h"

//class Unit;
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);

    enum GameState{
        StatePlaying,
        StateWin,
        StateLose
    };

    friend class Unit;
    friend class Tower;

    int gameStat;
//For function
    void gameIni(int x);//Tower, timer, score
    void Judge();
//For variables
    int x_bound;
    int y_under;
    //For minions
    int minion_w;
    int minion_h;
    int card1_num;
    int card2_num;
    int enemy_num;
    void minionIni();
    void enemyIni();
    void minionLaunch(int y);
    void enemyLaunch();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //QList<Unit*>minion;
    //For TowerBtn
    int btnMode;

signals:
    void oneSecond();

public slots:
    void countdown();
    void gameFin();

};

#endif // SCENE_H
