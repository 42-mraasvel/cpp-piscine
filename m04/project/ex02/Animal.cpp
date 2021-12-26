#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(const Animal& from)
	: type(from.type) {
	std::cout << "Animal Copy Constructor" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor" << std::endl;
}


Animal::Animal(const std::string& type)
	: type(type) {
	std::cout << "Animal(type) Constructor" << std::endl;
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
