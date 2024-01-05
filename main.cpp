#include <iostream>

#include "entity.h"
#include "enemy.h"
#include "boss.h"
#include "hero.h"
#include "battle.hpp"
#include <stdlib.h>
#include "factory.hpp"


using namespace std;

int main() {

   srand(1);

   hero* newPlayer = new hero;
   newPlayer->createClass();


   Factory f1;
   enemy* e1 = f1.buildEnemy();

   Factory f2;
   enemy* e2 = f2.buildEnemy();

   Factory f3;
   enemy* e3 = f3.buildEnemy();

   Factory f4;
   enemy* e4 = f4.buildEnemy();

   Factory f5;
   enemy* e5 = f5.buildEnemy();
   boss* b1 = f5.buildBoss();
  

   battle battleGame(e1, newPlayer);
   battleGame.playGame();
   
   if (newPlayer->getHealth() < 1) { delete newPlayer; return 0;}
   battle battleRound2(e2, newPlayer);
   battleRound2.playGame();

   if (newPlayer->getHealth() < 1) { delete newPlayer; return 0;}

   battle battleRound3(e3, newPlayer);
   battleRound3.playGame();

   if (newPlayer->getHealth() < 1) { delete newPlayer; return 0;}

   battle battleRound4(e4, newPlayer);
   battleRound4.playGame();
   if (newPlayer->getHealth() < 1) { delete newPlayer; return 0;}

   battle battleRound5(e5, newPlayer);
   battleRound5.playGame();
   if (newPlayer->getHealth() < 1) { delete newPlayer; return 0;}

   battle battleBossRound(b1, newPlayer);
   battleBossRound.playGame();
 
   std::cout << "\nYOU SAVED THE TOWN!!!\nYOU CAN GO HOME NOW.\n\n";

  
   delete newPlayer;
   return 0;
}
