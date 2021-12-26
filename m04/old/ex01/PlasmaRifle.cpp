#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
	: AWeapon("PlasmaRifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle& from)
	: AWeapon(from.getName(), from.getAPCost(), from.getDamage()) {}

PlasmaRifle::~PlasmaRifle() {}


PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();

	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
