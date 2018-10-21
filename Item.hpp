#pragma once
#include <string>

class Item {
public:
	Item(unsigned long bonusHP, unsigned long bonusDef, unsigned long bonusAT, unsigned long bonusMana, unsigned long bonusSP, int identity,std::string nameOfItem);
	Item();
	//setters to make the variables set.
	void setHealth(unsigned long bonusHP);
	void setDefense(unsigned long bonusDEF);
	void setAttack(unsigned long bonusAT);
	void setMana(unsigned long bonusMana);
	void setSpecial(unsigned long bonusSP);

	//getters to grab the values
	unsigned long getHealth();
	unsigned long getDefense();
	unsigned long getAttack();
	unsigned long getMana();
	unsigned long getSpecial();


	void returnItemEffect(Item& item);

private:
	unsigned long health;
	unsigned long defense;
	unsigned long attack;
	unsigned long mana;
	unsigned long special;
	int ID;
	std::string name;


};
