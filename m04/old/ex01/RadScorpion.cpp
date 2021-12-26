#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
	: Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& from)
	: Enemy(from) {}

RadScorpion::~RadScorpion() {
	std::cout <<  "* SPROTCH *" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->type = rhs.getType();
	this->hitpoints = rhs.getHP();

	return *this;
}
