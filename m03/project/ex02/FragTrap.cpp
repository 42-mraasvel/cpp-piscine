#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap("Default Name", 100, 100, 30) {
	std::cout << "FragTrap() default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& from)
	: ClapTrap(from) {
	std::cout << "FragTrap() copy constructor" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "~FragTrap() Destructor" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap(name) constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {

	if (this == &rhs) {
		return *this;
	}

	name = rhs.name;
	hitpoints = rhs.hitpoints;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	return *this;
}

void FragTrap::highFivesGuys(void) const {
	std::cout << "FR4G-TP A positive high fives request on the standard output" << std::endl;
}
