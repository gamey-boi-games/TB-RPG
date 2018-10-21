#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <string>
#include "hero.hpp"
#include "enemy.hpp"

Enemy enemy;

	//	constructors

Player::Player(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long m, unsigned long s){
	playerLv = l;
	playerHP = h;
	playerATK = a;
	playerDEF = d;
	playerMana = m;
	playerSP = s;
}

Player::Player(){
	playerLv = 1;
	maxHP = calcPlayerMaxHP();
	playerHP = maxHP;
	playerATK = 5;
	playerDEF = 4;
	playerMana = 10;
	playerExp = 0;
	playerSP = 7;
}


	//battle functions


void Player::takeDamage(unsigned long x){
	playerHP -= x;
}

void Player::useItem(Item& item) {
	//do things
}

void Player::openInventory(Inventory& inventory) {
	//clear the entire screen
	std::cout << "\033[2J\033[1;1H";
	std::cout << "Welcome to the inventory! Your items, weapons, and armor are stored here.\n What would you like to do? ";
	std::string choice;
	std::cin >> choice;
	std::cout << "\n";
	if (choice == "use item" || choice == "item") {
		std::cout << "item?";
//		useItem(Item &item);
	}
}

unsigned long Player::Heal(){
	heal = pow(playerLv, 1.9) + rand() % (playerLv * 10) + 1;
	playerHP+=heal;
	return heal;
}

void Player::attack(Enemy& enemy){
	damage = playerATK * 2 + rand() % (playerLv * 10) + 1;
	enemy.takeDamage(damage);
}

void Player::magicAttack(Enemy& enemy){
	magicDMG = rand() % playerMana + (playerLv * 10);
	enemy.takeDamage(magicDMG);
}


	//stat mutators  (setters)


unsigned long Player::calcPlayerLv(){
	return pow(playerExp / 5, 0.4) + 1;
}

unsigned long Player::calcPlayerMaxHP(){
	return pow(playerLv, 2.1) + 15;
}

void Player::setHP() {
	playerHP = maxHP;
}

unsigned long Player::calcPlayerATK(){
	return pow(playerLv, 2.05) + 10;
}

unsigned long Player::calcPlayerDEF(){
	return pow(playerLv, 2.1) + 10;
}

unsigned long Player::calcPlayerSP(){
	return pow(playerLv, 1.9) + 10;
}

unsigned long Player::calcPlayerMP(){
	return pow(playerLv, 2.2) + 20;
}

void Player::addXP(unsigned long x){
	playerExp+=x;
}


	//stat accessors  (getters)


long Player::Damage(){
	return damage;
}

unsigned long Player::getLv(){
	return playerLv;
}

unsigned long Player::getMaxHP(){
	return maxHP;
}

long Player::getHP(){
	return playerHP;
}

unsigned long Player::getATK(){
	return playerATK;
}

unsigned long Player::getDEF(){
	return playerDEF;
}

unsigned long Player::getSP(){
	return playerSP;
}

unsigned long Player::getMana(){
	return playerMana;
}

unsigned long Player::getXP() {
	return playerExp;
}

//a special setter so it gets its own section

void Player::update(){
	playerLv = calcPlayerLv();
	maxHP = calcPlayerMaxHP();
	playerHP = maxHP;
	playerATK = calcPlayerATK();
	playerDEF = calcPlayerDEF();
	playerSP = calcPlayerSP();
	playerMana = calcPlayerMP();
}
