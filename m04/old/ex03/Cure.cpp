#include <iostream>
#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure") {}

Cure::Cure(const Cure& from)
	: AMateria(from) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& rhs) {
	if (this == &rhs) {
		return *this;
	}

	_xp = rhs.getXP();

	return *this;
}

AMateria* Cure::clone() const {
	AMateria* cloned = new Cure(*this);
	return cloned;
}

void Cure::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "*heals " << target.getName() << "'s wounds *" << std::endl;
}
