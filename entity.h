#ifndef _entity_h_
#define _entity_h_
#include <string>


class Entity
{
protected:
    std::string name;
    double health;
    double attack;


    
public:
    Entity();
    Entity(std::string name, double health, double attack);
    ~Entity() {};




    virtual void print() = 0;
    
    void setHealth(double d);
    void setAttack(double d);
    void setName(std::string n);
    std::string getName();
    double getHealth();
    double getAttack();
};

#endif //_entity.h_
