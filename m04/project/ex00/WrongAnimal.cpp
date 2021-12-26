#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WRONGANIMAL() CONSTRUCTOR" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& from)
	: type(from.type) {}

WrongAnimal::~WrongAnimal() {
	std::cout << "~WRONGANIMAL() DESTRUCTOR" << std::endl;
}


WrongAnimal::WrongAnimal(const std::string& type)
	: type(type) {
	std::cout << "WRONGANIMAL(TYPE) CONSTRUCTOR" << std::endl;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	this->type = rhs.type;
	return *this;
}

const std::string& WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WRONG-ANIMAL" << std::endl;
}
