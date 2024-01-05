#ifndef __FACTORY_HPP_
#define __FACTORY_HPP_
#include "entity.h"
#include "enemy.h"
#include "boss.h"


class Factory {
   private:
      enemy* root;
      boss* bossRoot;
   public:
      Factory() { 
         this->root = nullptr;
         this->bossRoot = nullptr;
      }
      ~Factory() {
         delete this->root;
         delete this->bossRoot;
      }
      enemy* buildEnemy(); //builds enemy and returns a pointer to enemy
      boss* buildBoss();  //builds a boss, and returns a pointer to newly created boss


};

#endif // __FACTORY_HPP_
