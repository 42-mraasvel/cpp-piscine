#include <iostream>
#include "ScavTrap.hpp"

/* Constructors/Destructors */

ScavTrap::ScavTrap()
	: ClapTrap("Default Name", 100, 50, 20),  _gatekeeper_mode(false) {
	std::cout << "ScavTrap() default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& from)
	: ClapTrap(from), _gatekeeper_mode(false) {
	std::cout << "ScavTrap(const ScavTrap&) copy constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name, 100, 50, 20), _gatekeeper_mode(false) {
	std::cout << "ScavTrap(name) constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "~ScavTrap() destructor" << std::endl;
}

/* Operators */

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this == &rhs) {
		return *this;
	}

	name = rhs.name;
	hitpoints = rhs.hitpoints;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	return *this;
}

/* Methods */

void ScavTrap::attack(std::string const& target) const {
	std::cout << "SC4V-TP " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	_gatekeeper_mode = true;
	std::cout << "SC4V-TP " << name << " has entered Gate Keeper mode" << std::endl;
}
