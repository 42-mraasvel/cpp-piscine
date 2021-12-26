#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(const Brain& from) {
	std::cout << "Brain Copy Constructor" << std::endl;
	*this = from;
}

Brain::~Brain() {
	std::cout << "Brain Destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}
