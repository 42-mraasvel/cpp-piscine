#include <iostream>
#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(const std::string& name)
	: name(name) {
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim& from)
	: name(from.name) {}

Victim::~Victim() {
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim& Victim::operator=(const Victim& rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->name = rhs.name;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Victim& rhs) {
	out << "I'm " << rhs.GetName() << " and I like otters!" << std::endl;
	return out;
}

const std::string& Victim::GetName() const {
	return name;
}

void Victim::getPolymorphed() const {
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}
