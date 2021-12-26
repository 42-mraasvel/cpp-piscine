#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap() default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& from)
	: ClapTrap(from) {
	std::cout << "DiamondTrap() copy constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name",
	FragTrap::HitPoints,
	ScavTrap::EnergyPoints,
	FragTrap::AttackDamage),
	FragTrap(), ScavTrap(),
	name(name) {

	std::cout << "DiamondTrap(name) constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "~DiamondTrap() destructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this == &rhs) {
		return *this;
	}

	name = rhs.name;
	hitpoints = rhs.hitpoints;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;

	return *this;
}

void DiamondTrap::whoAmI() const {
	std::cout << "DI4M-TP Who am I? I am " << name << ", my grandparent's name is " << ClapTrap::name << std::endl;
}

const std::string& DiamondTrap::GetName() const {
	return name;
}
