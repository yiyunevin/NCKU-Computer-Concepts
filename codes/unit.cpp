#include "unit.h"

Unit::Unit(int hp, int atk, int pace, int atkRange, int team, QObject *parent)
    : QObject(parent), MaxHp(hp), hp(hp), atk(atk), pace(pace), atkRange(atkRange), team(team)
{
    attack = false;
}

Unit::~Unit()
{

}

int Unit::updateHp()
{
    return hp;
}
void Unit::onHit(int enemyAtk)
{
    hp -= enemyAtk;
}

void Unit::setTarget(int target)
{
    this -> target = target;
}


void Unit::active()
{
    if(!attack)
        unitWalk();
    else
        unitAttack();
}

void Unit::unitCrash()
{

}

void Unit::unitAttack()
{

}

void Unit::unitWalk()
{
    if(team == 1)
    {
        setPos(x() + pace, y());
    }
    else
    {
        setPos(x() - pace, y());
    }
}
