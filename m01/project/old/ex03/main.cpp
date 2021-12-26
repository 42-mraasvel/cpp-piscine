#include <bits/stdc++.h>
#include "ZombieHorde.hpp"

void TestHorde(int n) {
	ZombieHorde horde(n);
	horde.announce();

	std::cout << std::endl << "End of function so zombies are destroyed" << std::endl << std::endl;
}

int main(void) {
	TestHorde(10);
	std::cout << std::endl;
	TestHorde(5);

	return 0;
}
