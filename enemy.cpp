#include <cstdlib>
#include <cmath>
#include <random>
#include "enemy.hpp"
#include "hero.hpp"
#include "level.hpp"

Player player;

Area area;

class Item;

	//constructors

Enemy::Enemy(unsigned long l, unsigned long h, unsigned long a, unsigned long d, unsigned long s)
	: enemyLv(l)
	, currentEnemyHP(h)
	, maxEnemyHP(h)
	, enemyATK(a)
	, enemyDEF(d)
	, enemySP(s) {};


Enemy::Enemy()
	: enemyLv(2)
	, currentEnemyHP(20)
	, maxEnemyHP(20)
	, enemyATK(10)
	, enemyDEF(10)
	, enemySP(10) {};

	//functions for operational fight


void Enemy::attack(Player& player){
	player.takeDamage(Damage());
}

unsigned long Enemy::Damage(){
	enemyDMG = (1 + pow((enemyATK / 9) , 1.5) + rand() % 10 + 1);
	return enemyDMG;
}

void Enemy::takeDamage(unsigned long x){
	currentEnemyHP-=x;
}

//Item& Enemy::dropItem() {
//	return item;
//}


	//stats setters


unsigned long Enemy::calcEnemyLv(Area& area){
	enemyLv = area.getAreaBase() + (rand() % 5 + 0);
	return enemyLv;
}

unsigned long Enemy::calcEnemyMaxHP(){
	return pow(enemyLv, 2.2) + 20;
}

unsigned long Enemy::calcEnemyATK(){
	return pow(enemyLv, 2.1) + 10;
}

unsigned long Enemy::calcEnemyDEF(){
	return pow(enemyLv, 1.9) + 10;
}

unsigned long Enemy::calcEnemySP(){
	return pow(enemyLv, 2) + 10;
}

unsigned long Enemy::xpToDrop(){
	return (pow(enemyLv, 2) - (rand() % player.getLv() + 1)) + 10;
}


	//stat getters


long Enemy::getLv(){
	return enemyLv;
}

long Enemy::getMaxHP(){
	return maxEnemyHP;
}

long Enemy::getHealth(){
	return currentEnemyHP;
}

long Enemy::getATK(){
	return enemyATK;
}

long Enemy::getDEF(){
	return enemyDEF;
}

long Enemy::getSP(){
	return enemySP;
}

void Enemy::update(Area& area) {
	enemyLv = calcEnemyLv(area);
	maxEnemyHP = calcEnemyMaxHP();
	currentEnemyHP = maxEnemyHP;
	enemyATK = calcEnemyATK();
	enemyDEF = calcEnemyDEF();
	enemySP = calcEnemySP();
	xpToDrop();
}
