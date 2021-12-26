#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap();
	FragTrap(const FragTrap& from);
	~FragTrap();
	FragTrap(const std::string& name);

	FragTrap& operator=(const FragTrap& rhs);

	void highFivesGuys(void) const;

};

#endif /* FRAGTRAP_HPP */
