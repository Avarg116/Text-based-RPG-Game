
# Text-based RPG Game
 
## Project Description
This is a fun little text-based RPG along the lines of Wizardry, Ultima, and Dragon Quest.

## Class Diagram
![image](https://user-images.githubusercontent.com/91440304/143960865-42a2f4d5-cb29-4be5-8757-91b440dbcae3.png)
* The two design patterns implemented are **Strategy design** and **Abstract Factory design**.
* **Strategy design:** was chosen so that a regular mob enemy can attack with a weak or strong attack according a function set in the battle class. Additionally, it is useful as the boss will fluctuate between its attacks. The boss may attack with a strong or ultimate attack dealing massive amounts of damage to the player. The strategy design pattern allows for the changes of attack algorithm at runtime.
* **Abstract Factory design:** is implemented as "factory" where it produces and returns pointers to a respective enemy and boss. The interface of the factory allows for an enemy or boss to be built without specifying a value to the enemy/boss. I chose to utilize the abstract factory pattern as the enemy and boss are similarly related in classes. The choice of the design pattern allows for a randomly generated name to take the place of the name of the enemy/boss, and depending on what we want to build, correctly designates their respective stats according to my algorithms. This allows for the entities to be created by one function without any required parameters, thus making it easy to create instances of enemies/boss each with its own unique sets of stats/names.

 ## Screenshots
 * The player is prompted to input their desired name.

   ![image](https://user-images.githubusercontent.com/91440304/143950448-1cc13b1f-10c9-4a55-b061-7355c4a101a1.png)
 * After selecting a desired name, the game asks the player a question that will affect attack/defense stats.

   ![image](https://user-images.githubusercontent.com/91440304/143950693-03dcb52c-de40-4bf8-b592-d87b094cc0ff.png)
 * The game will then prompt the player to roll a dice to determine the player's luck stat. This luck stat will affect how well your attacks do against enemies.

   ![image](https://user-images.githubusercontent.com/91440304/143950967-604c8de2-68b2-46d6-8d2b-053b22debf31.png)
 * The player selects their preference of a "bow" or "magic" which will affect the player's ranged/magic stat.

   ![image](https://user-images.githubusercontent.com/91440304/143951228-4037b6f7-4a92-40d8-a640-0c2c0bf82f87.png)
 * The game displays the player's stats and we get into our first engagement against a random enemy. The game will ask the player to input the appropriate attack: melee, magic, or bow.

   ![image](https://user-images.githubusercontent.com/91440304/143951471-80a2eb47-300a-4ae6-8f23-4fcecf90870b.png)
 * The game will show whether your attack hit or missed. It displays "Enemy dealt damage" followed by how much damage you have done against the enemy. The game ouputs the enemy's attacks and whether they missed or not, as well as how much damage is done against the player. A message warns the player how much health they have left. The game prompts the player for another input.

   ![image](https://user-images.githubusercontent.com/91440304/143952266-d8bdc789-472a-4e13-8e3f-0647983ea9eb.png)
 * After the enemy has been slain, the game will output a message whether the enemy has dropped any loot or not. If they have, a message is displayed of what the player gained from the loot.

   ![image](https://user-images.githubusercontent.com/91440304/143952504-5febc2b3-9c99-4ee2-be20-76e4acc20fee.png)
 * If the enemy misses an attack against the player, a similar message like the one shown below will appear.

   ![image](https://user-images.githubusercontent.com/91440304/143952666-f81e2467-fff2-4ccd-8f5c-59380bb22757.png)
 * The player has encountered the boss when the name of the enemy is in ALL CAPS.

   ![image](https://user-images.githubusercontent.com/91440304/143952865-5b28d43c-7455-4f83-b468-e9134af06dcd.png)
 * Once the boss has been slain, the game outputs the following message stating you have "SAVED THE TOWN". The game has now concluded in a successful victory.

   ![image](https://user-images.githubusercontent.com/91440304/143953053-20a1c8a4-dbf3-4116-9e41-5689efa0db26.png)
 * If at any point in the game, does the player die, the game will output the following message and terminate the program.

   ![image](https://user-images.githubusercontent.com/91440304/143953227-d3acb835-edfc-4805-9a67-a73f5bf4c116.png)

 ## Installation/Usage
 * To be able to run and play my RPG Game into your local machine, you will need to recursively clone the Project Directory.
 * Once the repository has been cloned, enter the final project directory, and type in the command :
 * `pushd googletest ; git checkout f966ed ; popd` into the command line.
 * Once done, type : `cmake3 .` followed by `make`.
 * At last, run the executable through the command : `./rpgGame` which will begin the game.

 ## Testing
 * I tested my game through the `googletest` framework and submodule.
 * I tested the default constructors and constructors for the entity classes, enemy class, boss class, and hero class.
 * I tested functions such as the createClass in the hero class that actually builds our hero.
 * I created unit tests to test for the factory pattern and ran it in valgrind to see any potential memory leaks, fixing them accordingly.
