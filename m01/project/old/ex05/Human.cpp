#include "Human.hpp"

Human::Human() {}

Human::~Human() {}

const Brain& Human::getBrain() {
	return brain;
}

std::string Human::identify() const {
	return brain.identify();
}
