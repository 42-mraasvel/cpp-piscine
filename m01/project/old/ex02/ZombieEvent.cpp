#include <cstdlib>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {}
ZombieEvent::~ZombieEvent(void) {}

void ZombieEvent::setZombieType(std::string new_type) {
	this->_type = new_type;
}

/*
Because we are returning a pointer, zombie should be allocated on the heap using new
That way it won't be destroyed after the function finishes
`new` Does not have to be checked for it's return status, as C++ will throw an exception if it fails

However caller must delete the returned zombie
*/
Zombie *ZombieEvent::newZombie(std::string name) const {
	Zombie *zombie = new Zombie(name, _type);
	return zombie;
}

/*
Zombie stored on the stack because it's not needed outside of this function
*/
void ZombieEvent::randomChump(void) const {

	std::string name;

	/* Flip a coin */
	if (rand() % 2 == 0) {
		name = Zombie::RandomName(10);
	} else {
		name = Zombie::RandomNamePool();
	}

	Zombie zombie(name, _type);
	zombie.announce();

}
