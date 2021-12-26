#include "AWeapon.hpp"

AWeapon::AWeapon() {}

AWeapon::AWeapon(std::string const& name, int apcost, int damage)
	: name(name), apcost(apcost), damage(damage) {}

AWeapon::AWeapon(const AWeapon& from)
	: name(from.getName()), apcost(from.getAPCost()), damage(from.getDamage()) {}

AWeapon::~AWeapon() {}

AWeapon& AWeapon::operator=(const AWeapon& rhs) {

	if (this == &rhs) {
		return *this;
	}

	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();

	return *this;
}

std::string const& AWeapon::getName() const {
	return name;
}

int AWeapon::getAPCost() const {
	return apcost;
}

int AWeapon::getDamage() const {
	return damage;
}
