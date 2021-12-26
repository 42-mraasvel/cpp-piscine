#include "Zombie.hpp"

/*
Caller is expected to delete the returned array
*/
Zombie *zombieHorde(int N, std::string name) {

	if (N <= 0) {
		return NULL;
	}

	// Using array form of `new`
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return horde;
}
