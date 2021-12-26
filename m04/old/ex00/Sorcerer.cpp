#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

/* Constructors */

Sorcerer::Sorcerer(std::string name, std::string title)
	: name(name), title(title) {
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(const Sorcerer& from)
	: name(from.name), title(from.title) {}

Sorcerer::~Sorcerer() {
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& rhs) {
	if (this == &rhs) {
		return *this;
	}

	name = rhs.name;
	title = rhs.title;

	return *this;
}

const std::string& Sorcerer::GetName() const {
	return name;
}

const std::string& Sorcerer::GetTitle() const {
	return title;
}

std::ostream& operator<<(std::ostream& out, const Sorcerer& rhs) {
	out << "I am " << rhs.GetName() << ", " << rhs.GetTitle() << ", and I like ponies!" << std::endl;
	return out;
}

void Sorcerer::polymorph(Victim const& victim) const {
	victim.getPolymorphed();
}
