#include <iostream>
#include <fstream>
#include <string>
#include "mainmenu.hpp"
#include "hero.hpp"

class Player;

MainMenu::MainMenu() {
	std::cout << "Welcome to the main menu! Would you like to start a new game, load an old one, or exit the game? ";
}

void MainMenu::load(Player& player) {
	unsigned long firstNumber;
	std::ifstream saveFile;
	saveFile.open("stats.txt");
	saveFile >> firstNumber;
	player.addXP(firstNumber);
	player.update();
	saveFile.close();
}