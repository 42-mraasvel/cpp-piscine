#include <iostream>
#include "Rancor.hpp"

/*

Custom enemy rancor:

hp: 200
type: "Rancor"
On birth:  "* RARAOOROARHGOHRAOOR *"
Upon death: "* AAAURUAAUGUAGHAGUH *"

overloads takeDamage(amount) to take twice as much damage

*/

Rancor::Rancor()
	: Enemy(500, "Rancor") {
	std::cout << "* RARAOOROARHGOHRAOOR *" << std::endl;
}

Rancor::Rancor(const Rancor& from)
	: Enemy(from) {}

Rancor::~Rancor() {
	std::cout << "* AAAURUAAUGUAGHAGUH *" << std::endl;
}


Rancor& Rancor::operator=(const Rancor& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->type = rhs.getType();
	this->hitpoints = rhs.getHP();

	return *this;
}

void Rancor::takeDamage(int amount) {
	Enemy::takeDamage(amount * 2);
}
