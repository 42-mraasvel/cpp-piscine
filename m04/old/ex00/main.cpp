#include <iostream>
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Cat.hpp"

static void SomeMoreTests() {
	std::cout << " ** Some More Tests ** " << std::endl;

	Sorcerer merlin("Merlin", "the Enchanter");
	Cat cat("Bob");

	std::cout << cat;
	merlin.polymorph(cat);

}

static void MandatoryTests() {

	std::cout << std::endl << " ** Mandatory Tests ** " << std::endl;

	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
}

int main() {

	SomeMoreTests();

	MandatoryTests();
	return 0;
}
