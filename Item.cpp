#include "Item.hpp"

#include <iostream>
#include <string>




	Item::Item() {

	};

	//Establish weapons
	struct weapons {
		std::string name;
		int quantity;
		int damage;
		//bonus effects
	};
	//establish armors
	struct armors {
		std::string name;
		int quantity;
		int defense;
	};
	//establish potions
	struct potions {
		std::string name;
		int quantity;
		int health;
	};



	void Item::returnItemEffect(Item& item) {

	}

