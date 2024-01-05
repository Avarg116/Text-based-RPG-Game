#include "boss.h"

boss::boss() {
   this->name = "";
   this->health = 0;
   this->attack = 0;
   this->enemy_special = 0;
   this->enemy_chance = 0;
   this->ultimateMove = 0;
}

void boss::setUltimate(double ult) {
    this->ultimateMove = ult;
}

double boss::get_Ultimate() {
    return this->ultimateMove;
}

void boss::print() {
    std::cout << "Enemy: " << this->name << '\n';
    std::cout << "Health: " << getHealth() << '\n';
}
