#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "scene.h"

class Unit : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Unit(int hp,
                  int atk,
                  int pace,
                  int atkRange,
                  int team,
                  QObject *parent = 0);
    virtual ~Unit();
    enum minionStatus{
        StatusRight,
        StatusLeft,
        StatusStopRight,
        StatusStopLeft,
        StatusAtkRight,
        StatusAtkLeft
    };

    friend class Scene;

    int updateHp();
    void setTarget(int target);
    void onHit(int enemyAtk);
    void unitCrash();
    void unitAttack();
    void unitWalk();

private:
    const int MaxHp;
    int hp;
    int atk;
    int atkRange;
    int pace;
    int team;
    int target;
    int miniStat;

    bool attack;

signals:

public slots:
    virtual void active();
};

#endif // UNIT_H
