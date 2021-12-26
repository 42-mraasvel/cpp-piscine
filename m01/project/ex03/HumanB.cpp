#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) 
	: _name(name), _weapon(NULL) {}

/* Passed by reference, otherwise it will be a copied variable */
void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
