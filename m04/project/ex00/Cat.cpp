#include <iostream>
#include "Cat.hpp"

/* Constructors / Destructors */

Cat::Cat()
	: Animal("Cat") {
	std::cout << "CAT() CONSTRUCTOR" << std::endl;
}

Cat::Cat(const Cat& from)
	: Animal(from.getType()) {}

Cat::~Cat() {
	std::cout << "~CAT() DESTRUCTOR" << std::endl;
}


/* Operators */

Cat& Cat::operator=(const Cat& rhs) {
	(void)rhs;
	return *this;
}


/* Member Functions */

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
