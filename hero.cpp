#include "hero.h"
#include <iostream>


hero::hero() {
   this->name = "";
   this->health = 0;
   this->attack = 0;
   this->defense = 0;
   this->range = 0;
   this->magic = 0;
   this->luck = 0;
}

void hero::createClass() {
    int userInput = 0;
    std::string userName;
    
    std::cout << "Please, enter your character's name: ";
    std::getline(std::cin, userName);
    this->name = userName;

    std::cout << "\nAre you more strategic, or more of a warrior?\nIf strategic, input '1'.\nIf a warrior, input '2'.\n";
    std::cin >> userInput;

    while (userInput != 1 && userInput != 2) {
        std::cout << "Invalid selection! Try again!\n";
        std::cout << "\nAre you more strategic, or more of a warrior?\nIf stategic, input '1'.\nIf a warrior, input '2'.\n";
        std::cin >> userInput;
    }

       if (userInput == 1) {
          this->attack = 50;
          this->defense = 100;
       }
       else {
          this->attack = 100;
          this->defense = 50;
       }
    
    
    std::cout << "\nPress 1 to roll dice for luck stat...\n";
    std::cin >> userInput;

    while (userInput != 1) {
        std::cout << "\nPress 1 to roll dice for luck stat...\n";
        std::cin >> userInput;
    }
    
    int randNum = 0;
    randNum = rand() % 11 + 1;
    setLuck(randNum);
    
    std::cout << "Your hero has " << getLuck() << " luck out of 10\n";

    std::cout << "\nAre you more of a bow and arrow type, or a magic type user?\nEnter 1 for bow\nEnter 2 for magic\n";
    std::cin >> userInput;

    while (userInput != 1 && userInput != 2) {
        std::cout << "Invalid selection, try again\n";
        std::cout << "\nAre you more of a bow and arrow type, or a magic type user?\nEnter 1 for bow\nEnter 2 for magic\n";
        std::cin >> userInput;
    }
    
    if (userInput == 1) {
       setRange(100);
       setMagic(50);
    }
    else {
        setRange(50);
        setMagic(100);
    }
    
    setHealth(100);
    
    print();
}

void hero::setLuck(int l)
{
    this->luck = l;
} 
void hero::setDefense(double d)
{
    this->defense = d;
}
void hero::setRange(double d)
{
    this->range = d;
}
void hero::setMagic(double d)
{
    this->magic = d;
}


int hero::getLuck()
{
    return this->luck;
}

double hero::getDefense()
{
    return this->defense;
}
double hero::getRange()
{
    return this->range;
}
double hero::getMagic()
{
    return this->magic;
}
void hero::print()
{
    std::cout << "-------------------------" << std::endl;
    std::cout << getName() << "'s stats: " << std::endl;
    std::cout << "Health : " << getHealth() << std::endl;    
    std::cout << "Luck : " << getLuck() << std::endl;
    std::cout << "Defense : " << getDefense() << std::endl;
    std::cout << "Range : " << getRange() << std::endl;
    std::cout << "Magic : " << getMagic() << std::endl;
    std::cout << "-------------------------" << "\n\n";
}
