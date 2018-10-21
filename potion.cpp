#include "potion.hpp"
#include <iostream>
#include <string>

Potion::Potion() {
	heal = 0;
}

Potion::Potion(unsigned long healHP ){
	heal = healHP;
}

void Potion::setHeal(unsigned long healHP) {
	heal = healHP;
}

unsigned long Potion::getHeal() {
	return heal;
}
