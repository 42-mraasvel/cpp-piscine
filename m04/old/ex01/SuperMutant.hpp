#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

	SuperMutant();
	SuperMutant(const SuperMutant& from);
	~SuperMutant();

	SuperMutant& operator=(const SuperMutant& rhs);

	virtual void takeDamage(int amount);

private:


};

#endif /* SUPERMUTANT_HPP */
