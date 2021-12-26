#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist()
	: AWeapon("PowerFist", 8, 50) {}

PowerFist::PowerFist(const PowerFist& from)
	: AWeapon(from.getName(), from.getAPCost(), from.getDamage()) {}

PowerFist::~PowerFist() {}


PowerFist& PowerFist::operator=(const PowerFist& rhs) {

	if (this == &rhs) {
		return *this;
	}

	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();

	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
