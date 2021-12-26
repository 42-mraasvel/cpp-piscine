#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(const ScavTrap&);
	ScavTrap(const std::string& name);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	void attack(std::string const& target) const;
	void guardGate();

private:

	bool _gatekeeper_mode;

};

#endif /* SCAVTRAP_HPP */
