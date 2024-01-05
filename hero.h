#ifndef _hero_h_
#define _hero_h_
#include "entity.h"
#include <string>
#include <stdlib.h>

class hero : public Entity
{
protected:
    int luck;
    double range;
    double magic;
    double defense;
public:
    hero();
    hero(std::string name, double health, double attack, double defense, double range, double magic, int luck) : Entity(name, health, attack) , defense(defense), range(range), magic(magic), luck(luck) {}
    ~hero() {};
    int getLuck();
    double getRange();
    double getMagic();
    double getDefense();
    void createClass();    

    void print();
    void setLuck(int l);
    void setRange(double d);
    void setMagic(double d);
    void setDefense(double d);

};


#endif //_hero_h_
