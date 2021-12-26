#include <iostream>
#include "WrongCat.hpp"

/* Constructors / Destructors */

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {
	std::cout << "WRONGCAT() CONSTRUCTOR" << std::endl;
}

WrongCat::WrongCat(const WrongCat& from)
	: WrongAnimal(from.getType()) {}

WrongCat::~WrongCat() {
	std::cout << "~WRONGCAT() DESTRUCTOR" << std::endl;
}


/* Operators */

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	(void)rhs;
	return *this;
}


/* Member Functions */

void WrongCat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
