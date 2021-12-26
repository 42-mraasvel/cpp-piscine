#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) 
	: _name(name) {}

Zombie::~Zombie() {
	std::cout << "Destroying zombie: " << _name << std::endl;
}

void Zombie::announce(void) {
	std::cout << "<" <<_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}
