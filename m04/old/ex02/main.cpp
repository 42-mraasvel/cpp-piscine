#include <iostream>
#include <iomanip>
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

void ExampleTests() {
	std::cout << " **** EXAMPLE TESTS ****" << std::endl;

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);

	for (int i = 0; i < vlc->getCount(); ++i) {
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;
}

void TestGetCount() {
	std::cout << " **** GETCOUNT() TESTS ****" << std::endl;

	ISquad *squad = new Squad;
	// Add 10 marines
	const int NUM_MARINES = 4;
	for (int i = 0; i < NUM_MARINES; i++) {
		ISpaceMarine *new_entry = new TacticalMarine;
		squad->push(new_entry);
	}


	std::cout << "Number of marines: " << squad->getCount() << std::endl;
	delete squad;
}

void TestGetUnit() {
	std::cout << " **** GETUNIT() TESTS ****" << std::endl;
	ISquad *squad = new Squad;

	ISpaceMarine *bob = new AssaultTerminator;

	squad->push(bob);
	std::cout << "Number of marines: " << squad->getCount() << std::endl;
	squad->push(bob); // Try adding same marine twice
	std::cout << "Number of marines: " << squad->getCount() << std::endl;
	squad->push(0); // Try adding a NULL pointer
	std::cout << "Number of marines: " << squad->getCount() << std::endl;

	std::cout << (void *)bob << " : ORIGINAL" << std::endl;
	std::cout << (void *)squad->getUnit(0) << " : getUnit(0)" << std::endl;
	std::cout << (void *)squad->getUnit(1) << " : getUnit(1) - Out of bounds" << std::endl;

	delete squad;
}

void TestAssignation() {
	std::cout << " **** ASSIGNATION TESTS ****" << std::endl;
	Squad *squad = new Squad;

	for (int i = 0; i < 2; i++) {
		ISpaceMarine* new_entry = new AssaultTerminator;
		squad->push(new_entry);
	}

	Squad *copy = new Squad;

	// Typecast so that the Squad's assignation operator is used
	*copy = *squad;

	// Deep copy: they don't share the same pointer to the same place in memory
	// That way there are no problems when deleting the Squads
	delete squad;
	std::cout << "Copy size after deleting squad: " << copy->getCount() << std::endl;
	delete copy;
}

void TestCopyConstructor2(Squad copy) {
	ISpaceMarine* new_entry = new AssaultTerminator;
	copy.push(new_entry);
	std::cout << "Deleting copy from copied squad with size: " << copy.getCount() << std::endl;
}

void TestCopyConstructor() {
	std::cout << " **** COPY CONSTRUCTOR TESTS ****" << std::endl;
	Squad *squad = new Squad;

	for (int i = 0; i < 2; i++) {
		ISpaceMarine* new_entry = new TacticalMarine;
		squad->push(new_entry);
	}

	TestCopyConstructor2(*squad);

	std::cout << "Deleting original squad withsize: " << squad->getCount() << std::endl;
	delete squad;
}

void TestMethods() {

	std::cout << " **** METHOD TESTS ****" << std::endl;

	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *job = new AssaultTerminator;

	bob->battleCry();
	bob->rangedAttack();
	bob->meleeAttack();
	job->battleCry();
	job->rangedAttack();
	job->meleeAttack();

	delete bob;
	delete job;
}

enum TestCases {
	EXAMPLE,
	GETCOUNT,
	GETUNIT,
	ASSIGNATION,
	COPYCONSTRUCTOR,
	METHODS
};

int main(void) {

	int input;

	std::cout	<< "Tests:" << std::endl \
				<< "[" << EXAMPLE << "] - " << "Example" << std::endl \
				<< "[" << GETCOUNT << "] - " << "getCount" << std::endl \
				<< "[" << GETUNIT << "] - "  << "getUnit" << std::endl \
				<< "[" << ASSIGNATION << "] - "  << "Assignation" << std::endl \
				<< "[" << COPYCONSTRUCTOR << "] - "  << "CopyConstructor" << std::endl \
				<< "[" << METHODS << "] - "  << "Methods" << std::endl;
	std::cout << "Input: ";
	std::cin >> input;
	if (!std::cin.good()) {
		std::cerr << "Weird input" << std::endl;
		return (0);
	}
	std::cout << std::endl;

	switch(input) {
		case(EXAMPLE):
			ExampleTests();
			break;
		case(GETCOUNT):
			TestGetCount();
			break;
		case(GETUNIT):
			TestGetUnit();
			break;
		case(ASSIGNATION):
			TestAssignation();
			break;
		case(COPYCONSTRUCTOR):
			TestCopyConstructor();
			break;
		case(METHODS):
			TestMethods();
			break;
		default:
			std::cerr << "Weird input" << std::endl;
			break;
	}

	return 0;
}
