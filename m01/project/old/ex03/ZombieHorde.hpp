#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {

public:

	ZombieHorde(int n);
	~ZombieHorde();

	void announce() const;

private:

	int const _size;
	Zombie *_zombies;

};

#endif /* ZOMBIEHORDE_HPP */
