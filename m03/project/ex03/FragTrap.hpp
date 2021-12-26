#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:

	FragTrap();
	FragTrap(const FragTrap& from);
	~FragTrap();
	FragTrap(const std::string& name);

	FragTrap& operator=(const FragTrap& rhs);

	void highFivesGuys(void) const;

protected:

	static const int HitPoints;
	static const int EnergyPoints;
	static const int AttackDamage;

};

#endif /* FRAGTRAP_HPP */
