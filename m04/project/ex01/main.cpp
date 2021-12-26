#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void ArrayTest() {

	std::cout << " ** ARRAY / LEAK TEST ** " << std::endl;

	const int SIZE = 2;

	Animal* table[SIZE];

	// 50% DOG, 50% CAT
	for (int i = 0; i < SIZE; i++) {
		std::cout << std::endl;
		if (i < SIZE / 2) {
			table[i] = new Dog();
		} else {
			table[i] = new Cat();
		}
	}

	// Deleting Animal* calls the correct Dog and Cat destructors
	// this is because the destructor is virtual
	for (int i = 0; i < SIZE; i++) {
		std::cout << std::endl;
		delete table[i];
	}
}

void CopyTest() {
	std::cout << " ** (DEEP) COPY TEST ** " << std::endl;

	Cat* a = new Cat();
	std::cout << std::endl;

	// Make a deep copy: BrainPointers don't point to same brain
	std::cout << "-Creating copy of A-" << std::endl;
	Cat* b = new Cat(*a);
	std::cout << std::endl;


	std::cout << "-Destroying B-" << std::endl;
	delete b;

	// Because it's a DEEP copy: deleting A doesn't cause problems
	std::cout << std::endl << "-Destroying A-" << std::endl;
	delete a;

}

int main(void) {
	ArrayTest();
	std::cout << std::endl;
	CopyTest();
	return 0;
}
