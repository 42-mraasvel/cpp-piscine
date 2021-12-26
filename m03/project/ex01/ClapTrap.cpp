#include <iostream>
#include "ClapTrap.hpp"

/* Constructors / Destructors */

ClapTrap::ClapTrap()
	: name("Default Name"), hitpoints(10), energy_points(10), attack_damage(0) {

	std::cout << "ClapTrap() default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& from)
	: name(from.name), hitpoints(from.hitpoints),
	energy_points(from.energy_points), attack_damage(from.attack_damage) {
	
	std::cout << "ClapTrap(const ClapTrap&) copy constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitpoints(10), energy_points(10), attack_damage(0) {

	std::cout << "ClapTrap(name) constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int hp, unsigned int ep, unsigned int ad)
	: name(name), hitpoints(hp), energy_points(ep), attack_damage(ad) {
	std::cout << "ClapTrap(name, health, energy, attack) Constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "~ClapTrap() Destructor" << std::endl;
}

/* Operators */

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {

	if (this == &rhs) {
		return *this;
	}

	name = rhs.name;
	hitpoints = rhs.hitpoints;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	return *this;
}

/* Public Methods */

void ClapTrap::attack(std::string const& target) const {
	std::cout << "CLAP-TP " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (amount > hitpoints) {
		hitpoints = 0;
	} else {
		hitpoints -= amount;
	}

	std::cout << "CL4P-TP " << name << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	hitpoints += amount;

	std::cout << "CL4P-TP " << name << " is repaired for " << amount << " health" << std::endl;
}
