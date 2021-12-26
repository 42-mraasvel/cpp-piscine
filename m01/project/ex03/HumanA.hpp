#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

/*

Why weapon as a reference?

- It will always have a weapon (doesn't have to be NULL)
- It's initialized with the constructor
- Weapon doesn't have to be changed

*/

class HumanA {

public:

	HumanA(const std::string& name, Weapon& weapon);

	void attack(void) const;

private:

	const std::string _name;
	Weapon& _weapon;

};

#endif /* HUMANA_HPP */
