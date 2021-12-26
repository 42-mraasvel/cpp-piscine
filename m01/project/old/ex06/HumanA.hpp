#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

/*
Question: Why weapon reference?

The only way to initialize the weapon is through the constructor, then there's no reason for it to be a pointer
Since the value does not have to be changed, and it does not have to be NULL
*/

class HumanA {

public:

	HumanA(const std::string name, Weapon& weapon);
	~HumanA();

	void attack() const;

private:

	const std::string _name;
	Weapon& _weapon;

};

#endif /* HUMANA_HPP */
