#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

/*

Why weapon as a pointer?

- It can be uninitialized or NULL, this is not possible with a reference
- It can be changed now as well

*/

class HumanB {

public:

	HumanB(const std::string& name);

	void attack(void) const;
	void setWeapon(Weapon& weapon);

private:

	const std::string _name;
	Weapon *_weapon;

};

#endif /* HUMANB_HPP */
