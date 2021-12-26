#include <iostream>
#include "Peon.hpp"

Peon::Peon(const std::string& name)
	: Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon& from)
	: Victim(from) {}

Peon::Peon()
	: Victim() {}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon& Peon::operator=(const Peon& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->name = rhs.GetName();

	return *this;
}

void Peon::getPolymorphed() const {
	std::cout << name << " has been turned into a pink pony!" << std::endl;
}
