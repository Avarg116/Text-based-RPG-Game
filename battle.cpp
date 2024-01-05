#include "battle.hpp"
#include <string>

bool battle::playGame() {
std::cout << "\nWhat's that coming ahead??? \n\n";
std::cout << "You encountered a " << this->enemyClass->getName() << "!\n\n";
this->enemyClass->print();

bool battle= true;
while(battle == true)
{
    std::cout << "\nChoose an attack \n1. Melee Attack \n2. Magic Attack \n3. Bow Attack\n";
    int choice;
    std::cin >> choice;

    while(choice != 1 && choice != 2 && choice != 3)
    {
        std::cout << "\nChoose an attack:" << std::endl;
	std::cout << "1. Melee Attack \n2. Magic Attack \n3. Bow Attack" << std::endl;
	std::cin >> choice;
    }
    double damage;
    if(choice == 1)
    {
        damage= this->heroClass->getAttack();
    }
    else if(choice == 2)
    {
        damage= this->heroClass->getMagic();
    }
    else
    {
	damage= this->heroClass->getRange();
    }
    
    std::cout << "\nYou get ready to fight!" << "\n\n";
    
    bool hit =  chance(heroClass->getLuck());
    if(hit == true) {
        enemyClass->setHealth(enemyClass->getHealth() - damage);
        std::cout << "Enemy dealt damage!" << std::endl;
	std::cout << "Enemy health: " << enemyClass->getHealth() << "\n\n";
    }
    else
    {
        std::cout << "???" << std::endl;
	std::cout << "You missed!" << std::endl;
    } //aded this in to check
    bool deadEnemy;
    deadEnemy= isDead(enemyClass->getHealth());
    if(deadEnemy == false)
    {
        heroClass->setHealth(heroClass->getHealth() - enemyAttack(enemyClass->getName(), enemyClass->getAttack(), enemyClass->get_chance(), heroClass->getDefense())); //check
	bool deadHero;
        deadHero= isDead(heroClass->getHealth());
	if(deadHero == true)
        {
            battle= false;
	    std::cout << "YOU DIED. GAME OVER.\n";
            return false;
        }
        else
        {
            std::cout << "Be careful! Your remaining health is: " << heroClass->getHealth() << "!" <<endl;
        }
    }
    else
    {
        battle= false;
        std::cout << "Da da da DAAAA da da DAAA DA DAAAA!!!" << endl;
       	std::cout << "You won against the enemy!" << "\n\n";

    	std::cout << "You looked to see if it dropped anything...\n" << endl;
        items(heroClass);

	return true;
    }
 }
}


bool battle::chance(int luck) {
    int hit;
    hit= rand() % 5 + 1;
    if(luck < hit)
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool battle::isDead(double health)
{
    if(health < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double battle::enemyAttack(string name, double attack, int chance, double defense)
{
    std::cout << "Look out! " << name << " is going to attack!" << "\n\n";
    
    int hit;
    hit= rand() % 5 + 1;   
    if(chance >= hit)
    {
    
        std::cout << "You got hit by " << name << "! Hurry and get up!" << endl;
        double damagePlayer;
        
        if (defense > 55) {
        damagePlayer = (defense / 20) + rand() % 10;
        }
        else {
        damagePlayer = (defense/4)+attack;
        }
        return damagePlayer;
    }
    else
    {
        std::cout << name << " missed completely!" <<endl;
	return 0;
    }
}
	  	    
	 
void battle::items(hero* theHero)
{
    int chanceOfLoot;
    chanceOfLoot=  rand() % 5 + 1;

    if(theHero->getLuck() < chanceOfLoot)
    {
        std::cout << "Tough luck, you get nothing" << endl;
    }
    else
    {
    int lootType = rand() % 6 + 1;
    int lootRarity = rand() % 5 + 1;

    if(lootType = 1)
    {
        theHero->setHealth(theHero->getHealth() + lootRarity);
        std::cout << "-----------------------------------\n";
        std::cout << "Your health has increased " << lootRarity << " point!" << std::endl;
        std::cout << "Your current health is now: " << theHero->getHealth() << std::endl;
        std::cout << "-----------------------------------\n";
    }
    else if(lootType = 2)
    {
        theHero->setAttack(theHero->getAttack() + lootRarity);
        std::cout << "Your attack has increased " << lootRarity << " point!" << std::endl;
        std::cout << "Your current attack is now: " << theHero->getAttack() << std::endl;
    }
    else if(lootType = 3)
    {
        theHero->setDefense(theHero->getDefense() + lootRarity);
        std::cout << "Your defense has increased " << lootRarity << " point!" << std::endl;
        std::cout << "Your current defense is now: " << theHero->getDefense() << std::endl;
    }
    else if(lootType = 4)
    {
        theHero->setRange(theHero->getRange() + lootRarity);
        std::cout << "Your range has increased " << lootRarity << " point!" << std::endl;
        std::cout << "Your current range is now: " << theHero->getRange() << std::endl;
    }
    else if(lootType = 5)
    {
        theHero->setMagic(theHero->getMagic() + lootRarity);
        std::cout << "Your magic has increased " << lootRarity << " point!" << std::endl;
        std::cout << "Your current magic is now: " << theHero->getMagic() << std::endl;
    }
    else if(lootType = 6)
    {
        theHero->setLuck(theHero->getLuck() + lootRarity);
        std::cout << "Your luck has increased " << lootRarity << " point!" << std::endl;
        std::cout << "Your current luck is now: " << theHero->getLuck() << std::endl;
    }
    }
} 
