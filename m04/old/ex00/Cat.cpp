#include <iostream>
#include "Cat.hpp"

Cat::Cat()
	: Victim() {}

Cat::Cat(const std::string& name)
	: Victim(name) {
	std::cout << "Meow..." << std::endl;
}

Cat::Cat(const Cat& from)
	: Victim(from) {}

Cat::~Cat() {
	std::cout << "MEOW" << std::endl;
}


Cat& Cat::operator=(const Cat& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->name = rhs.GetName();

	return *this;
}

void Cat::getPolymorphed() const {
	std::cout << name << " the cat turned into a dog!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cat& rhs) {
	out << "Meow, I am a cat named " << rhs.GetName() << std::endl;
	return out;
}
