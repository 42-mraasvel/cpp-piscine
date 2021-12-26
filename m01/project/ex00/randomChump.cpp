#include <iostream>
#include "Zombie.hpp"

/*
Create zombie on stack because it's not needed outside of this function
*/
void randomChump(std::string name) {
	std::cout << "[randomChump]: Creating new zombie: " << name << std::endl;
	Zombie chump(name);
	chump.announce();
}
