#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {}

Zombie::~Zombie(void) {}

void Zombie::announce(void) const {
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}



void Zombie::SetName(std::string name) {
	this->_name = name;
}

void Zombie::SetType(std::string type) {
	this->_type = type;
}


/* Random Functions */

std::string Zombie::RandomNamePool(void) {
	static std::string pool [] = {
		"Charmander",
		"Squirtle",
		"Bulbasaur",
		"Pikachu",
		"Eevee",
		"Gengar",
		"Snorlax",
		"Mewtwo"
	};
	int const POOL_SIZE = sizeof(pool) / sizeof(std::string);

	return pool[rand() % POOL_SIZE];
}

std::string Zombie::RandomTypePool(void) {
	static std::string pool [] = {
		"Fire",
		"Water",
		"Grass",
		"Electric",
		"Normal",
		"Dark",
		"Psychic",
		"Fairy"
	};
	int const POOL_SIZE = sizeof(pool) / sizeof(std::string);


	return pool[rand() % POOL_SIZE];
}


/*
String with random ascii characters
There are 95 printable characters, ranging from 32-126
*/
std::string Zombie::RandomName(size_t len) {
	std::string name;
	for (size_t i = 0; i < len; i++) {
		name.push_back((rand() % 95) + 32);
	}
	return name;
}
