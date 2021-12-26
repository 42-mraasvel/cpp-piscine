#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:

	DiamondTrap();
	DiamondTrap(const DiamondTrap& from);
	DiamondTrap(const std::string& name);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& rhs);

	void whoAmI() const;
	const std::string& GetName() const;

private:

	std::string name;

};

#endif /* DIAMONDTRAP_HPP */
