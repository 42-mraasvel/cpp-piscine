#include <iostream>
#include <cstdlib>
#include "ZombieEvent.hpp"

void TestSetZombieType(ZombieEvent& event, std::string name, std::string type) {

	event.setZombieType(type);

	Zombie *zombie = event.newZombie(name);
	zombie->announce();

	delete zombie;
}

void TestRandomZombie(ZombieEvent& event) {

	event.setZombieType(Zombie::RandomTypePool());
	event.randomChump();

}

int main(void) {

	srand(time(0)); // Seed so output is different every time

	ZombieEvent event;

	std::cout << "newZombie() tests:" << std::endl << std::endl;

	TestSetZombieType(event, "Pikachu", "Electric");
	TestSetZombieType(event, "Charmander", "Fire");

	std::cout << std::endl << std::endl << "randomChump() tests:" << std::endl << std::endl;

	TestRandomZombie(event);
	TestRandomZombie(event);
	TestRandomZombie(event);
	return 0;
}
