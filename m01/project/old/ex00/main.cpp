#include <iostream>
#include "Pony.hpp"

void ShowPonyInstanceCount(void) {
	std::cout << "Number of pony instances: " << Pony::GetInstanceCount() << std::endl << std::endl;
}

void TestHeap(void) {
	ponyOnTheHeap();
	ShowPonyInstanceCount(); // Shows that the instance was deleted
}

void TestStack(void) {
	ponyOnTheStack();
	ShowPonyInstanceCount(); // Shows that the instance was deleted
}

int main(void) {

	/* Heap Pony */
	TestHeap();

	std::cout << std::endl;

	/* Stack Pony */
	TestStack();

	return 0;
}
