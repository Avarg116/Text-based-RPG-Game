#ifndef __BOSS_H_
#define __BOSS_H_

#include "enemy.h"
#include "entity.h"
class boss : public enemy {
protected:
    double ultimateMove;

public:
     boss(); //default constructor
     boss(std::string name, double health, double attack, double special, int chance, double ultimateAttack) : enemy(name, health, attack, special, chance), ultimateMove(ultimateAttack) {}
     ~boss() {};
     double get_Ultimate();
     virtual void print();
     void setUltimate(double ult);
};

#endif // __BOSS_H_
