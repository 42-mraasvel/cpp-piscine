#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

/* Constructors / Destructors */

Cat::Cat()
	: Animal("Cat") {
	std::cout << "Cat Constructor" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& from)
	: Animal(from.getType()) {
	std::cout << "Cat Copy Constructor" << std::endl;
	// Deep copy = allocate new area, instead of copying pointer
	brain = new Brain();
	*brain = *from.brain;
}

Cat::~Cat() {
	std::cout << "Cat Destructor" << std::endl;
	delete brain;
}


/* Operators */

Cat& Cat::operator=(const Cat& rhs) {
	// Brain for this animal is already allocated, so we only need to copy the underlying data
	*brain = *rhs.brain;
	return *this;
}


/* Member Functions */

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
