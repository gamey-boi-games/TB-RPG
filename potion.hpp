#pragma once
#include "Item.hpp"
#include <string>

class Potion : public Item {
public:
	
	Potion();
	Potion(unsigned long healHP);
	void setHeal(unsigned long healHP);
	unsigned long getHeal();

private:
	unsigned long heal;
};
