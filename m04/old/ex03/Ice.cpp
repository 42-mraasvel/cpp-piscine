#include <iostream>
#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice") {}

Ice::Ice(const Ice& from)
	: AMateria(from) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& rhs) {
	if (this == &rhs) {
		return *this;
	}

	_xp = rhs.getXP();

	return *this;
}

AMateria* Ice::clone() const {
	AMateria* cloned = new Ice(*this);
	return cloned;
}

void Ice::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "*shoots an ice bolt at " << target.getName() << std::endl;
}
