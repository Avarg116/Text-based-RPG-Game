#include "enemy.h"
#include <iostream>

enemy::enemy() {
   this->name = "";
   this->health = 0;
   this->attack = 0;
   this->enemy_special = 0;
   this->enemy_chance = 0;
}

void enemy::set_special(double s) {
   this->enemy_special = s;
}

void enemy::set_chance(int c) {
   this->enemy_chance = c;
}

double enemy::get_special() {
   return this->enemy_special;
}

int enemy::get_chance() {
   return this->enemy_chance;
}

void enemy::print() {
  std::cout << "Enemy: " << this->name <<  std::endl;
  std::cout << "Enemy Health: " << getHealth() << "\n\n";
}   
