#include "factory.hpp"
#include <vector> //for a vector of strings
#include <string> //for strings
#include <stdlib.h> //for rand option

enemy* Factory::buildEnemy() { //builds an enemy, with names, etc, and returns a pointer to that enemy
   std::vector<std::string> adjectivesE = {"Angry", "Dirty", "Annoyed", "Tired", "Hungry", "Rude"};
   int indexAdj = rand() % 6; //will get a value of 0 - 5, used to get adjective of enemy
   std::vector<std::string> namesE = {"Goblin", "Wolf", "Demon", "Skeleton", "Brute", "Ghost"};
   int indexName = rand() % 6; //will get a value of 0 - 5 , used for name of enemy
   std::string enemyName = adjectivesE.at(indexAdj) + " " + namesE.at(indexName);

   //we got the enemy name, now get its health, attack, special, chance

   double enemyHealth = rand() % 101 + 50; // 50 - 100
   double enemyAttack = rand() % 11 + 1; // 1 - 10
   double enemySpecial = rand() % 21 + 10; // 10 - 20
   int enemyChance = rand() % 10; // 0 - 10

   this->root = new enemy(enemyName, enemyHealth, enemyAttack, enemySpecial, enemyChance);
   return this->root; //generated an enemy

}

boss* Factory::buildBoss() {
   std::vector<std::string> adjB = {"BRUTAL", "WIRED", "DEMONIC", "FIERY", "HAUNTING"};
   int indexAdjB = rand() % 5; //0 - 4
   std::vector<std::string> namesB = {"OVERLORD", "WARLOCK", "SORCERER", "DRAGON", "MECHA-KNIGHT"};
   int indexNameB = rand() % 5;
   std::string bossName = adjB.at(indexAdjB) + " " + namesB.at(indexNameB);

   //we got the boss name, now get its health, attack, special, chance, ultMove
   double bossHealth = rand() % 251 + 200; // 200 - 250
   double bossAttack = rand() % 41 + 20; //20 - 40
   double bossSpecial = rand() % 61 + 50; // 50 - 60
   int bossChance = rand() % 9 + 1; // 1 - 8
   double bossUlt = rand() % 201 + 100; // 100 - 200

   this->bossRoot = new boss(bossName, bossHealth, bossAttack, bossSpecial, bossChance, bossUlt);
   return this->bossRoot;
}

