#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "battlesystem.hpp"
#include "hero.hpp"
#include "dragon.hpp"
#include "mainmenu.hpp"
#include "level.hpp"


int main(int argc, char const *argv[]) {

	/*sf::Window window(sf::VideoMode(600, 840), "Gamey_Boi");

	//set vertical synchronization to true so tearing doesn't happen
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}*/
		//create an object of Player so playing through the game makes a little more sense
		Player player;

		//construct a MainMenu object to initialize said main menu
		MainMenu game;

		//get user input for whatever the hell they're planning
		std::string choice;
		while (true) {
			std::cin >> choice;
			if (choice == "start") {
				break;
			}
			else if (choice == "load") {
				game.load(player);
				break;
			}
			else if (choice == "exit") {
				return 0;
			}
			else {
				std::cout << "That's not an option. Please enter a valid choice. ";
			}
		}

		std::cout << "\nWelcome. You wake up in a place you've never seen before, and this land once unbeknownst to you is \nfilled with strange creatures. \nYou look around, and there is a river to your right filled with the most plump looking fish.\nTo your left is a field with a huge open expanse that stretches on for miles, fairies fluttering in \nthe wind while gracing the land and animals with their magic and presence.\nThere also appear to be dangerous animals such as dragons very far off in the distance.\nIn front of you is mountain range with the purest white snow-capped peaks, and you can\nsee all sorts of flying animals in the sky. It truly is a beautiful sight.\nSo, where would you like to go?\n";
		while (true) {
			std::cout << "\nNorth, West, East, or South? ";
			std::string direction;
			std::cin >> direction;
			std::cout << "\n";
			if (direction == "West" || direction == "west") {
				Area area(30);
				std::cout << "\nYou look to your left towards the massive open expanse,\nand realize it's probably a bad idea in your current\ncondition to go that way right now.\n";
				battle(player, area);
				std::cout << "You have slain the enemy, and now you are tired. You decide to go to sleep. As you fall asleep under the mystic willow tree,\n you feel uneasy. When you come to, there is another enemy standing over you!\n";
				battle(player, area);
				std::cout << "After defeating the enemy, you are exhausted. 'What was that? Where am I?'\n All these questions race by in your mind as you get lulled to sleep by nature under the \n mystic willow tree. When you come to, you see an enemy charging! Prepare for battle!\n";
				battle(player, area);
				break;
			}
			else if (direction == "South" || direction == "south") {
				std::cout << "You look behind you and see something you didn't notice before.\nThere's an abandoned looking village hidden under the shroud of a beautiful forest.\nI'd be careful though, because it looks like you could get lost easily.\n";
				std::cout << "Do you enter the forest at your own risk? Enter or leave?\n";
				std::string choice;
				std::cin >> choice;
				if (choice == "Enter" || choice == "enter") {
					Area area(10);
					std::cout << "\nYou enter the forest, and immediately lose yourself in the foliage that's full of beautiful shades of gold, red, and green.\nAfter wandering around for a bit, you head\ninto the abandoned village to try and get an idea of what happened, and get any gear if possible.\nAfter venturing into some small village houses, you find a much larger house that was presumably belonged to the chief of the tribe.\nDo you enter the house or no? ";
					std::string choice;
					std::cin >> choice;
					if (choice == "Enter" || choice == "enter") {
						battle(player, area);
					}
					else {
						std::cout << "You decide not to enter the forest and turn back around\n";
					}
				}
				break;
			}
			else if (direction == "East" || direction == "east") {
				Area area(1);
				std::cout << "You walk up to the river to get a drink. Man are you thirsty!\nAfter drinking some water, you remember about the fish and consider catching one. What do you want to do?\n";
				break;
			}
			else if (direction == "North" || direction == "north") {
				Area area(5);
				std::cout << "Traveling north will take a few days time in your current condition, and although\nthe view is beautiful you're also not up to a fight if anything happens.\nI'd like you to reconsider.";
				break;
			}
			else {
				std::cout << "That's not a direction. Try again.\n";
			}
		}
	//}
	return 0;
}