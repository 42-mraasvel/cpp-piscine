#include <iostream>
#include "Karen.hpp"

void Karen::complain(std::string level) {

	static const std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int i;
	for (i = 0; i < 4; i++) {
		if (level == levels[i]) {
			break;
		}
	}

	// Pretty sure the subject was hinting to use switch case
	switch (i) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

/*
Private methods
*/

void Karen::debug(void) {
	std::cout	<< "[ DEBUG ]" << std::endl\
				<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." \
				<< std::endl \
				<< "I just love it!" << std::endl << std::endl;
}

void Karen::info(void) {
	std::cout	<< "[ INFO ]" << std::endl \
				<< "I cannot believe adding extra bacon cost more money." << std::endl \
				<< "You don’t put enough! "\
				<< "If you did I would not have to ask for it!" << std::endl << std::endl;
}

void Karen::warning(void) {
	std::cout	<< "[ WARNING ]" << std::endl \
				<< "I think I deserve to have some extra bacon for free." << std::endl \
				<< "I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void Karen::error(void) {
	std::cout	<< "[ ERROR ]" << std::endl \
				<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}
