#include <iostream>
#include "Dog.hpp"

/* Constructors / Destructors */

Dog::Dog()
	: Animal("Dog") {
	std::cout << "DOG() CONSTRUCTOR" << std::endl;
}

Dog::Dog(const Dog& from)
	: Animal(from.getType()) {}

Dog::~Dog() {
	std::cout << "~DOG() DESTRUCTOR" << std::endl;
}


/* Operators */

Dog& Dog::operator=(const Dog& rhs) {
	(void)rhs;
	return *this;
}


/* Member Functions */

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
