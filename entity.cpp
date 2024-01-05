#include "entity.h"


Entity::Entity() {
   this->name = "";
   this->health = 0;
   this->attack = 0;
}


Entity::Entity(std::string fullName, double health, double attack)
{
    this->name = fullName;
    this->health = health;
    this->attack = attack;
}

void Entity::setName(std::string s)
{
    this->name = s;
}
void Entity::setHealth(double d)
{
    this->health = d;
}
void Entity::setAttack(double d)
{
    this->attack = d;
}

std::string Entity::getName()
{
    return this->name;
}
double Entity::getHealth()
{
    return this->health;
}
double Entity::getAttack()
{
    return this->attack;
}