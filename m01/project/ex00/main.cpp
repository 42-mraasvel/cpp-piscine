#include <iostream>
#include "Zombie.hpp"

Zombie * newZombie(std::string name);
void randomChump(std::string name);

int main(void) {

	randomChump("Zombie on the stack");

	std::cout << std::endl;

	Zombie *zombie = newZombie("Zombie on the heap");
	zombie->announce();
	delete zombie;

	std::cout << std::endl << "End of program!" << std::endl;
	return 0;
}
