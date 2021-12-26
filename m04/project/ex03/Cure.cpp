#include <iostream>
#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure") {}

Cure::Cure(const Cure& from)
	: AMateria(from) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure&) {
	return *this;
}

AMateria* Cure::clone() const {
	AMateria* copy = new Cure(*this);
	return copy;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
