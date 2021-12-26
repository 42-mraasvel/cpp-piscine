#include "AMateria.hpp"

AMateria::AMateria()
	: _xp(0) {}

AMateria::AMateria(std::string const& type)
	: _type(type), _xp(0) {}

AMateria::AMateria(const AMateria& from)
	: _type(from.getType()), _xp(from.getXP()) {}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->_xp = rhs._xp;

	return *this;
}

AMateria::~AMateria() {}


std::string const& AMateria::getType() const {
	return _type;
}

unsigned int AMateria::getXP() const {
	return _xp;
}

// Increases xp by 10
void AMateria::use(ICharacter& target) {
	(void)target;
	_xp += 10;
}
