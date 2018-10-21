#include "Item.hpp"

#include <iostream>
#include <string>

Item::Item() {
	health = 0;
	defense = 0;
	attack = 0;
	mana = 0;
	special = 0;
	ID = 0;
	name = "";
	}


	Item::Item(unsigned long bonusHP, unsigned long bonusDef, unsigned long bonusAT, unsigned long bonusMana, unsigned long bonusSP,int identity, std::string nameOfItem) {
		health = bonusHP;
		defense = bonusDef;
		attack = bonusAT;
		mana = bonusMana;
		special = bonusSP;
		ID = identity;
		name = nameOfItem;
	};
	
	void Item::setHealth(unsigned long bonusHP) {
		health = bonusHP;
	}

	void Item::setAttack(unsigned long bonusAT) {
		attack = bonusAT;
	}

	void Item::setDefense(unsigned long bonusDef) {
		defense = bonusDef;
	}

	void Item::setMana(unsigned long bonusMana) {
		mana = bonusMana;
	}

	void Item::setSpecial(unsigned long bonusSP) {
		special = bonusSP;
	}

	unsigned long Item::getAttack() {
		return attack;
	}

	unsigned long Item::getHealth() {
		return health;
	}

	unsigned long Item::getDefense() {
		return defense;
	}

	unsigned long Item::getMana() {
		return mana;
	}

	unsigned long Item::getSpecial() {
		return special;
	}



	void Item::returnItemEffect(Item& item) {

	}

