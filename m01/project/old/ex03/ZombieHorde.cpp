#include <iostream>
#include <cstdlib>
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _size(n) {

	std::cout << "Creating " << n << " Zombies" << std::endl << std::endl;

	/* Allocating an array of type Zombie using `new[]` operator */
	_zombies = new Zombie[n];

	/* Assign names and types */
	for (int i = 0; i < n; i++) {
		_zombies[i].SetName(Zombie::RandomName());
		_zombies[i].SetType(Zombie::RandomType());
	}
}

ZombieHorde::~ZombieHorde() {
	/* Deleting an array of zombies  using `delete[]` operator*/
	delete [] _zombies;
}

void ZombieHorde::announce() const {
	for (int i = 0; i < _size; i++) {
		std::cout << i << " : ";
		_zombies[i].announce();
	}
}
