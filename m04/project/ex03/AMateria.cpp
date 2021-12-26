#include "AMateria.hpp"

/* Constructors/Destructors */
AMateria::AMateria(std::string const& type)
	: type(type) {}

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& from)
	: type(from.getType()) {}

AMateria::~AMateria() {}


/* Operators */
AMateria& AMateria::operator=(const AMateria&) {
	return *this;
}


/* Member Functions */
std::string const& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter&) {}
