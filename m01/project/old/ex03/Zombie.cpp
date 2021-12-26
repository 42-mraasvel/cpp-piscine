#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {}

Zombie::Zombie(const Zombie& from) : _name(from._name), _type(from._type) {}

Zombie::~Zombie(void) {
	std::cout << _name << " (" << _type << ")" << " is released (destructor)." << std::endl;
}

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

/* 50/50 between choosing from a pool, and getting a random ASCII string */
std::string Zombie::RandomType(void) {
	if (rand() % 2 == 0) {
		return RandomTypePool();
	} else {
		return RandomString(10);
	}
}

std::string Zombie::RandomName(void) {
	if (rand() % 2 == 0) {
		return RandomNamePool();
	} else {
		return RandomString(10);
	}

}

/*
String with random ascii characters
There are 95 printable characters, ranging from 32-126
*/
std::string Zombie::RandomString(size_t len) {
	std::string name;
	for (size_t i = 0; i < len; i++) {
		name.push_back((rand() % 95) + 32);
	}
	return name;
}

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
