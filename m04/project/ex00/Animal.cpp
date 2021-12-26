#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "ANIMAL() CONSTRUCTOR" << std::endl;
}

Animal::Animal(const Animal& from)
	: type(from.type) {}

Animal::~Animal() {
	std::cout << "~ANIMAL() DESTRUCTOR" << std::endl;
}


Animal::Animal(const std::string& type)
	: type(type) {
	std::cout << "ANIMAL(TYPE) CONSTRUCTOR" << std::endl;
}


Animal& Animal::operator=(const Animal& rhs) {
	this->type = rhs.type;
	return *this;
}

const std::string& Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "ANIMAL" << std::endl;
}
