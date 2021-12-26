#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"

const int Character::MaxAP = 40;

Character::Character()
	: name("Default Name"),
	action_points(40),
	weapon(NULL) {}

Character::Character(std::string const& name)
	: name(name),
	action_points(40),
	weapon(NULL) {}

Character::Character(const Character& from)
	: name(from.name),
	action_points(from.action_points),
	weapon(from.weapon) {}

Character& Character::operator=(const Character& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->name = rhs.name;
	this->action_points = rhs.action_points;
	this->weapon = rhs.weapon;

	return *this;
}

Character::~Character() {}

std::ostream& operator<<(std::ostream& out, const Character& rhs) {

	const AWeapon *weapon = rhs.getWeapon();

	out << rhs.getName() << " has " << rhs.getAP() << " AP and";
	if (weapon != NULL) {
		out << " wields a " << weapon->getName() << std::endl;
	} else {
		out << " is unarmed" << std::endl;
	}
	return out;
}

void Character::recoverAP() {
	action_points += 10;
	if (action_points > MaxAP) {
		action_points = MaxAP;
	}
}

void Character::equip(AWeapon *weapon) {
	this->weapon = weapon;
}

void Character::attack(Enemy *enemy) {

	if (weapon == NULL || weapon->getAPCost() > action_points) {
		return;
	}

	std::cout << name << " attacks " << enemy->getType() << " with a " << weapon->getName() << std::endl;

	action_points -= weapon->getAPCost();
	weapon->attack();
	enemy->takeDamage(weapon->getDamage());

	// Does it make sense to delete it inside of this function?
	// How does the caller know whether or not the enemy was deleted?
	if (enemy->getHP() <= 0) {
		delete enemy;
	}
}

std::string const& Character::getName() const {
	return name;
}

const AWeapon* Character::getWeapon() const {
	return weapon;
}

int Character::getAP() const {
	return action_points;
}
