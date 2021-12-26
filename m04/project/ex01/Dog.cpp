#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

/* Constructors / Destructors */

Dog::Dog()
	: Animal("Dog") {
	std::cout << "Dog Constructor" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& from)
	: Animal(from.getType()) {

	std::cout << "Dog Copy Constructor" << std::endl;
	// Deep copy = allocate new area, instead of copying pointer
	brain = new Brain();
	*brain = *from.brain;
}

Dog::~Dog() {
	std::cout << "Dog Destructor" << std::endl;
	delete brain;
}


/* Operators */

Dog& Dog::operator=(const Dog& rhs) {
	// Brain for this animal is already allocated, so we only need to copy the underlying data
	*brain = *rhs.brain;
	return *this;
}


/* Member Functions */

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
