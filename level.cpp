#include <iostream>
#include "level.hpp"

Area::Area() {

}

Area::Area(int x) {
	std::cout << "You've entered a new area! ";
	areaBase = x;
}



int Area::getAreaBase() {
	return areaBase + 1;
}