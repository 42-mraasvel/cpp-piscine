#include <iostream>
#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {
	std::cout << "Human used Melee Attack on " << target << std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "Human used Ranged Attack on " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "Human used Intimidating Shout on " << target << std::endl;
}


void Human::action(std::string const & action_name, std::string const & target) {

	const int size = 3;

	// Array of pointer to member functions
	static void (Human::*actions[size])(std::string const&) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	// Array of action names
	static std::string names[size] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	for (int i = 0; i < size; i++) {
		if (names[i] == action_name) {
			(this->*(actions[i]))(target);
		}
	}
}

