#include <iostream>
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice") {}

Ice::Ice(const Ice& from)
	: AMateria(from) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice&) {
	return *this;
}

AMateria* Ice::clone() const {
	AMateria* copy = new Ice(*this);
	return copy;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
