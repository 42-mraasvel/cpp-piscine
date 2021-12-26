#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
	: Enemy(170, "SuperMutant"){
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& from)
	: Enemy(from) {}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant& rhs) {
	(void)rhs;
	return *this;
}

void SuperMutant::takeDamage(int amount) {

	// Underflow protection ?
	if (amount - 3 > amount) {
		return;
	}

	Enemy::takeDamage(amount - 3);
}
