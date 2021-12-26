#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:

	ScavTrap();
	ScavTrap(const ScavTrap&);
	ScavTrap(const std::string& name);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	void attack(std::string const& target) const;
	void guardGate();

protected:

	static const int HitPoints;
	static const int EnergyPoints;
	static const int AttackDamage;
	bool _gatekeeper_mode;

};

#endif /* SCAVTRAP_HPP */
