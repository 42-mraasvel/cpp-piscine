#include <iostream>
#include "Zombie.hpp"

/*
Create zombie on heap so it can be returned
*/
Zombie * newZombie(std::string name) {
	std::cout << "[newZombie]: Creating zombie: " << name << std::endl;
	Zombie *zombie = new Zombie(name);
	return zombie;
}
