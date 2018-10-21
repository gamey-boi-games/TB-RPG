#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
#include "enemy.hpp"
#include "hero.hpp"
#include "level.hpp"

int battle(Player& player, Area& area) {

	//declare a random number for use in deciding enemy count
	int number_of_enemies = rand() % 5 + 1;

	//make multiple enemy objects for the fight
	std::vector<std::unique_ptr<Enemy>> enemy;

	for (int i = 0; i < number_of_enemies; ++i) {
		enemy.emplace_back(std::make_unique<Enemy>());
	}
	std::cout << "number of enemies to fight: " << enemy.size() << "\n";
	for (int x = number_of_enemies - 1; x > -1 ; x--) {

		std::cout << "Area base level is: " << area.getAreaBase() << "\n";

		//update enemy so it'll appear a random level
		//	uniform_int_distribution didn't *quite* work. Ask Jack later
		enemy[x]->update(area);

		//introduce and start the battle loop
		std::cout << "\nIt seems you've encountered an enemy! Its level is " << enemy[x]->getLv() << " and it has " << enemy[x]->getHealth()
			<< " health!\n Your level is " << player.getLv() << ".\n";

		//have it loop infinitely for obvious reasons
		while (true) {
			std::string choice;
			//loop battle options with cin so there's no infinite loop here
			while (true) {
				std::cout << "\nWhat do you do? Attack, Heal, use magic, or run? ";
				std::cin >> choice;
				std::cout << "\n";

				//provide options for battle
				if (choice == "Attack" || choice == "attack") {
					player.attack(*enemy[x]);
					std::cout << "You attacked the enemy! " << "The enemy has " << enemy[x]->getHealth() << " health left!\n";
					break;
				}
				else if (choice == "Heal" || choice == "heal") {
					player.Heal();
					if (player.getHP() > player.getMaxHP()) {
						player.setHP();
						std::cout << "You healed and are feeling reinvigorated! You now have " << player.getHP() << " health!\n";
					}
					break;
				}
				else if (choice == "Magic" || choice == "magic") {
					player.magicAttack(*enemy[x]);
					std::cout << "Your magic dealt significant damage to the enemy! The enemy has " << enemy[x]->getHealth() << " left!\n";
					break;
				}
				else if (choice == "run") {
					std::cout << "You successfully ran away!\n";
					return 0;
				}
				else {
					std::cout << "That's not a command. Re-enter your choice.\n";
				}
			}

			if (player.getHP() <= 0 || enemy[x]->getHealth() <= 0) {
				if (enemy[x]->getHealth() <= 0) {
					player.addXP(enemy[x]->xpToDrop());
					player.update();
					std::cout << "You have slain the enemy! Congratulations!\n";
					std::cout << "You have gained " << enemy[x]->xpToDrop() << " experience!\n";
					std::cout << "You are now level " << player.getLv() << "\n";


					std::cout << "Your stats are as follows. \nHealth: " << player.getHP() << "\nAttack: " << player.getATK()
						<< "\nDefense: " << player.getDEF() << "\nMana: " << player.getMana()
						<< "\nAverage damage dealt per hit: " << player.Damage();
					std::cout << "\n";

					std::cout << "Your enemy's stats are as follows. \nLevel: " << enemy[x]->getLv()
						<< "\nHealth: " << enemy[x]->getHealth() << "\nAttack: " << enemy[x]->getATK()
						<< "\nDefense: " << enemy[x]->getDEF() << "\nAverage damage dealt per hit: " << enemy[x]->Damage();
					std::cout << "\n";
					enemy.erase(enemy.begin() + x);

					//iterate from the number of enemies to 0 and delete each defeated enemy. Shouldn't get an out of bounds error in theory

					break;
				}
				if (player.getHP() <= 0) {
					std::cout << "You have been defeated...\n";
					break;
				}
			}
			enemy[x]->attack(player);
			std::cout << "The enemy has attacked you!\n";
			std::cout << "You have " << player.getHP() << " HP left!\n";
		}
	}
	std::ofstream saveFile;
	saveFile.open("stats.txt");
		saveFile << player.getXP() << "\n" << player.getLv()
		<< player.getMaxHP() << "\n" << player.getATK()
		<< player.getDEF() << "\n" << player.getSP()
		<< "\n" << player.getMana() << "\n";
	
	saveFile.close();

	return 0;
}

/*
	Instantiate multiple enemy class objects using:
	std::vector<T> v(objCount);
	
*/
