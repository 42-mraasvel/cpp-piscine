#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void ExampleTests() {

	std::cout << " **** EXAMPLE TESTS **** " << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("Me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void MateriaTests() {

	std::cout << " **** MATERIA TESTS **** " << std::endl;

	ICharacter* target = new Character("TARGET");

	AMateria* tmp = new Ice();

	// Use 5 times
	tmp->use(*target);
	tmp->use(*target);
	tmp->use(*target);
	tmp->use(*target);
	tmp->use(*target);

	// XP is 50
	std::cout << "XP of " << tmp->getType() << " is " << tmp->getXP() << std::endl;

	// Clone has same XP and type
	AMateria *clone = tmp->clone();
	std::cout << "XP of cloned " << clone->getType() << " is " << clone->getXP() << std::endl;

	clone->use(*target);
	std::cout << "XP of " << tmp->getType() << " is " << tmp->getXP() << std::endl;
	std::cout << "XP of cloned " << clone->getType() << " is " << clone->getXP() << std::endl;

	std::cout << std::endl << "After 'clone = tmp'" << std::endl;
	// Assignation test
	*clone = *tmp;
	std::cout << "XP of " << tmp->getType() << " is " << tmp->getXP() << std::endl;
	std::cout << "XP of cloned " << clone->getType() << " is " << clone->getXP() << std::endl;


	delete clone;
	delete tmp;
	delete target;
}

void CharacterTests() {
	std::cout << " **** CHARACTER TESTS **** " << std::endl;


	ICharacter *me = new Character("Bob");

	AMateria* ice0 = new Ice();
	AMateria* ice1 = new Ice();
	AMateria* ice2 = new Ice();
	AMateria* ice3 = new Ice();

	// Nulptr equip: nonexistant
	me->equip(0);

	// Equip all ice
	me->equip(ice0);
	me->equip(ice1);
	me->equip(ice2);
	me->equip(ice3);

	// Equip at full inventory: ignored
	AMateria* ice4 = new Ice();
	me->equip(ice4);
	delete ice4;

	// 4 equipped, so index 3 is max index
	me->use(-1, *me);
	me->use(3, *me);
	me->use(4, *me);

	// If we unequip ice3, it will not be deleted by me
	me->unequip(3);
	delete ice3;
	// Just unequipped 3, so doesn't do anything
	me->use(3, *me);

	AMateria* cure0 = new Cure();
	me->unequip(1);
	delete ice1;
	// Equip cure0, will be equipped at index 1 (lowest available index)
	me->equip(cure0);
	me->use(1, *me);
	std::cout << "Cure0 xp: " << cure0->getXP() << std::endl;

	// Create a deep copy using assignation overload
	std::cout << std::endl << "Create a copy: *copy = *me" << std::endl;

	ICharacter* copy = new Character("Copy");
	// Equip new before assigning, to show that it's deleted
	copy->equip(new Ice());
	*(Character *)copy = *(Character *)me;

	copy->use(0, *me);
	copy->use(0, *copy);
	std::cout << "Original Ice0 xp: " << ice0->getXP() << std::endl;
	delete copy;

	// Deleting me will also delete all equipped AMateria*
	delete me;
}

void MateriaSourceTests() {
	std::cout << " **** MATERIA SOURCE TESTS **** " << std::endl;

	ICharacter* example = new Character("Example");
	IMateriaSource* src = new MateriaSource();


	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	// Basic test
	AMateria* ice0 = src->createMateria("ice");
	std::cout << ice0->getType() << " has " << ice0->getXP() << " XP" << std::endl;
	delete ice0;

	// Invalid type test
	AMateria* invalid = src->createMateria("NotAType");
	std::cout << "createMateria() with invalid type return: " << invalid << std::endl;

	// Learn a new skill with some xp
	AMateria* cure0 = new Cure();
	cure0->use(*example);
	src->learnMateria(cure0);

	// Clone the skill with xp to show it cloned it properly
	AMateria* cure1 = src->createMateria("cure");
	std::cout << cure1->getType() << " has " << cure1->getXP() << " XP" << std::endl;

	// Since it's a copy we can and should delete it
	delete cure1;

	delete src;
	delete example;
}



/* UI handling */

const char* GetOption(int index) {
	static const char* options[] = {
		"EXAMPLE",
		"MATERIA",
		"CHARACTER",
		"MATERIA SOURCE"
	};

	const int size = sizeof(options) / sizeof(char *);

	if (index >= size || index < 0) {
		return 0;
	}

	return options[index];
}

typedef void (*TestFunc_t)(void);

TestFunc_t GetTester(int index) {

	static const TestFunc_t testers[] = {
		ExampleTests,
		MateriaTests,
		CharacterTests,
		MateriaSourceTests
	};

	const int size = sizeof(testers) / sizeof(TestFunc_t);

	if (index < 0 || index >= size) {
		std::cerr << "Invalid Option" << std::endl;
		return 0;
	}

	return testers[index];
}

void PrintOptions() {

	std::cout << "TESTS:" << std::endl;

	// Print options
	int i = 0;
	while (true) {
		const char *option = GetOption(i);
		if (option == 0) {
			break;
		}
		std::cout << "[" << i << "] " << option << std::endl;
		i++;
	}
}

int main(void) {

	PrintOptions();
	// Get input
	int choice;
	std::cout << "Enter choice: ";
	std::cin >> std::noskipws >> choice;
	if (!std::cin.good()) {
		std::cerr << "Invalid Option" << std::endl;
		return 0;
	}

	// Call test function
	TestFunc_t tester = GetTester(choice);
	if (tester != 0) {
		tester();
	}

	return 0;
}
