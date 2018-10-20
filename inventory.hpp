#pragma once

class Item;

class Inventory {
public:

	//constructor
	Inventory();

	//every day inventory accessing methods
	//these of which are settersip

	void addItem(std::vector<std::unique_ptr<Item>> inventory, Item& item, int quantity);
	void removeItem(Item& item, int quantity);

	//these of which are getters
	void displayItems();
	Item* getItem();

private:
	
};