#include <iostream>
#include "Lightsaber.hpp"

/*
Lightsaber : custom weapon type

Name: "Lightsaber"
Damage: 80
APcost: 15
Output of attack(): "* BJJJJJJJZZZZHKKHKJZJJJJJJJZZZZZZZvvvwwommmmm *"
*/

Lightsaber::Lightsaber()
	: AWeapon("Lightsaber", 15, 80) {}

Lightsaber::Lightsaber(const Lightsaber& from)
	: AWeapon(from) {}

Lightsaber::~Lightsaber() {}

Lightsaber& Lightsaber::operator=(const Lightsaber& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();

	return *this;
}

void Lightsaber::attack() const {
	std::cout << "* BJJJJJJJZZZZHKKHKJZJJJJJJJZZZZZZZvvvwwommmmm *" << std::endl;
}
