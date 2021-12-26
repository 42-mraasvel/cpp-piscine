#include <iostream>
#include <cstdlib>
#include "classes.hpp"

Base* generate(void) {

	int random_number = rand() % 3;

	switch (random_number) {
		case 0:
			std::cout << "Generated: A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated: B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated: C" << std::endl;
			return new C();
			break;
		default:
			return NULL;
	}
}

/*
dynamic_cast using pointer returns NULL if cast is impossible
*/
void identify(Base* p) {
	A* a = dynamic_cast<A*> (p);
	if (a != NULL) {
		std::cout << "A" << std::endl;
		return;
	}

	B* b = dynamic_cast<B*> (p);
	if (b != NULL) {
		std::cout << "B" << std::endl;
		return;
	}

	C* c = dynamic_cast<C*> (p);
	if (c != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
}

/*
dynamic_cast using reference throws exception if cast is impossible
*/
void identify(Base& p) {


	try {
		A& a = dynamic_cast<A&> (p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch(const std::exception&) {}

	try {
		B& b = dynamic_cast<B&> (p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch(const std::exception&) {}

	try {
		C& c = dynamic_cast<C&> (p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch(const std::exception&) {}

}

int main() {
	srand(time(0));
	Base* ptr = generate();

	std::cout << "PTR identify(): ";
	identify(*ptr);
	std::cout << "REF identify(): ";
	identify(ptr);

	delete ptr;
	return 0;
}
