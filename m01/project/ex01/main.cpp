#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

void TestHorde(int n, std::string name) {
	Zombie *horde = zombieHorde(10, name);

	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}

	// Array form of `delete`: comment out to get a leak
	delete [] horde;
}

int main(void) {
	
	TestHorde(10, "Alfred");
	return 0;
}
