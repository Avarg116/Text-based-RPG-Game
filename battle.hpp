#ifndef BATTLE_H
#define BATTLE_H
#include "entity.h"
#include "hero.h"
#include "enemy.h"
#include "boss.h"

#include<string>
using namespace std;

class battle {

private: 
   enemy* enemyClass;
   hero* heroClass;

public:
   battle(enemy* enemyObj, hero* characterObj) { this->enemyClass = enemyObj; this->heroClass = characterObj;} 

   bool playGame();
   bool chance(int luck);
   bool isDead(double health);
   double enemyAttack(string name, double attack, int chance, double defense);
   void items(hero* theHero);
};

#endif
