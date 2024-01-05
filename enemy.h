#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "entity.h"
#include <iostream>

class enemy : public Entity {
protected: 
   int enemy_chance; 
   double enemy_special;

public: 
   enemy(); //default constructor
   enemy(std::string name, double health, double attack, double special, int chance) : Entity(name, health, attack) , enemy_special(special), enemy_chance(chance) {}
   ~enemy() {};


   double get_special();
   int get_chance();
   virtual void print();
   void set_special(double s);
   void set_chance(int c);
};


#endif // __ENEMY_H_
