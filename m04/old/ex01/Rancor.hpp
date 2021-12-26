#ifndef RANCOR_HPP
# define RANCOR_HPP

# include "Enemy.hpp"

class Rancor : public Enemy {

public:

	Rancor();
	Rancor(const Rancor& from);
	~Rancor();

	Rancor& operator=(const Rancor& rhs);

	virtual void takeDamage(int amount);

};

#endif /* RANCOR_HPP */
