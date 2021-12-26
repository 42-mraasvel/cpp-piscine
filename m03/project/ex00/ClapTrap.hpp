#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(const ClapTrap&);
	ClapTrap(const std::string& name);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& rhs);

	void attack(std::string const& target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:

	std::string name;
	unsigned int hitpoints;
	unsigned int energy_points;
	unsigned int attack_damage;

};

#endif /* CLAPTRAP_HPP */
