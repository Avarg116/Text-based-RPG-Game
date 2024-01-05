#include "entity.h"
#include "enemy.h"
#include "boss.h"
#include "gtest/gtest.h"
#include "hero.h"
#include "factory.hpp"
#include "battle.hpp"

TEST(enemyClass, test1) {
   enemy* enemy1 = new enemy("angry goblin", 55.5, 8.9, 4.44, 3);

   EXPECT_EQ(enemy1->get_chance(), 3);
   EXPECT_DOUBLE_EQ(enemy1->get_special(), 4.44);
   delete enemy1;
}


TEST(enemyClass, test2) {
   enemy* enemy2 = new enemy("angry mage", 49, 3.9, 2.22, 1);

   EXPECT_EQ(enemy2->getName(), "angry mage");
   EXPECT_DOUBLE_EQ(enemy2->getHealth(), 49);
   EXPECT_DOUBLE_EQ(enemy2->getAttack(), 3.9);
   EXPECT_EQ(enemy2->get_chance(), 1);
   EXPECT_FLOAT_EQ(enemy2->get_special(), 2.22);
   delete enemy2;
} 

TEST(enemyClass, test3) {
   Entity* enemy3 = new enemy("angry wolf", 29, 3.1, 3.69, 4);
   
   EXPECT_DOUBLE_EQ(enemy3->getHealth(), 29);
   EXPECT_EQ(enemy3->getName(), "angry wolf");
   delete enemy3;
}
TEST(enemyClass, defaultConstructor) {
   enemy* enemy4 = new enemy;
   EXPECT_DOUBLE_EQ(enemy4->getHealth(), 0);

   delete enemy4;
}

TEST(enemyClass, defaultConstructor2) {
   enemy* toad = new enemy;
   EXPECT_EQ(toad->get_chance(), 0);
   delete toad;
}

TEST(bossClass, test1) {
   boss* boss1 = new boss("Shadow Wolf", 100, 21.2, 3.99, 3, 30.2);

   EXPECT_EQ(boss1->getName(), "Shadow Wolf");
   delete boss1;
}

TEST(bossClass, test2) {
   Entity* boss2 = new boss("Shadow Kanji", 100, 22.2 , 6.99, 2, 12.3);
   EXPECT_EQ(boss2->getHealth(), 100);
   delete boss2;
}
TEST(bossClass, defaultConstructor) {
   boss* boss4 = new boss();
   EXPECT_EQ(boss4->getName(), "");
   EXPECT_DOUBLE_EQ(boss4->getHealth(), 0);
   EXPECT_DOUBLE_EQ(boss4->getAttack(), 0);
   EXPECT_DOUBLE_EQ(boss4->get_special(), 0);
   EXPECT_DOUBLE_EQ(boss4->get_Ultimate(), 0);
   EXPECT_EQ(boss4->get_chance(), 0);

   delete boss4;
}


TEST(heroClass, constructor) {
   hero* hero1 = new hero("jack", 100, 20, 10, 5, 7, 4);
   EXPECT_DOUBLE_EQ(hero1->getMagic() , 7);
   delete hero1;
}

TEST(heroClass, defaultConstructor) {
   hero* newHero = new hero;
   EXPECT_DOUBLE_EQ(newHero->getHealth() , 0);
   EXPECT_DOUBLE_EQ(newHero->getAttack() , 0);
   EXPECT_DOUBLE_EQ(newHero->getDefense() , 0);
   EXPECT_DOUBLE_EQ(newHero->getRange() , 0);
   EXPECT_DOUBLE_EQ(newHero->getMagic() , 0);
   EXPECT_DOUBLE_EQ(newHero->getLuck() , 0);

   delete newHero;
}

TEST(heroClass, setters) {
   hero* hero2 = new hero;
   hero2->setHealth(50);
   hero2->setAttack(60);
   hero2->setDefense(70);
   hero2->setRange(80);
   hero2->setMagic(90);
   hero2->setLuck(100);

   EXPECT_DOUBLE_EQ(hero2->getHealth() , 50);
   EXPECT_DOUBLE_EQ(hero2->getAttack() , 60);
   EXPECT_DOUBLE_EQ(hero2->getDefense() , 70);
   EXPECT_DOUBLE_EQ(hero2->getRange() , 80);
   EXPECT_DOUBLE_EQ(hero2->getMagic() , 90);
   EXPECT_DOUBLE_EQ(hero2->getLuck() , 100);

   delete hero2;
}
/*
TEST(heroClass, createClass) {
    hero* newHero2 = new hero;
    newHero2->createClass();

    EXPECT_DOUBLE_EQ(newHero2->getLuck(), 6);
    delete newHero2;
}

TEST(heroClass, createClass2) {
    hero* newHero3 = new hero;
    newHero3->createClass();
    EXPECT_DOUBLE_EQ(newHero3->getLuck(), 10);
    delete newHero3;
}
*/
TEST(factory, createEnemy) {
   Factory factory1;
   enemy* brandNewE = factory1.buildEnemy();
   EXPECT_EQ(brandNewE->getName(), "Dirty Brute");
   EXPECT_DOUBLE_EQ(brandNewE->get_special(), 18);
   EXPECT_EQ(brandNewE->get_chance(), 5);

   Factory factory2;
   enemy* brandNewE2 = factory2.buildEnemy();
   EXPECT_EQ(brandNewE2->getName(), "Hungry Goblin");
   EXPECT_DOUBLE_EQ(brandNewE2->get_special(), 12);
   EXPECT_EQ(brandNewE2->get_chance(), 7);


   Factory factory3;
   enemy* brandNewE3 = factory3.buildEnemy();
   EXPECT_EQ(brandNewE3->getName(), "Annoyed Wolf");
   EXPECT_DOUBLE_EQ(brandNewE3->get_special(), 13);
   EXPECT_EQ(brandNewE3->get_chance(), 6);

}  

TEST(factory, createBoss) {
   Factory factory1;
   boss* newBossMade = factory1.buildBoss();

   EXPECT_EQ(newBossMade->getName(), "DEMONIC WARLOCK");
   EXPECT_DOUBLE_EQ(newBossMade->get_Ultimate(), 123);
   EXPECT_EQ(newBossMade->get_chance(), 7);
}

TEST(factory, createEnemyAndBoss) {
   Factory factoryBig;
   enemy* factoryEnemy = factoryBig.buildEnemy();
   boss* factoryBoss = factoryBig.buildBoss();

   EXPECT_EQ(factoryEnemy->getName(), "Annoyed Demon");
   EXPECT_DOUBLE_EQ(factoryEnemy->getHealth(), 57);


   EXPECT_EQ(factoryBoss->getName(), "DEMONIC SORCERER");
   EXPECT_DOUBLE_EQ(factoryBoss->getHealth(), 247);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
