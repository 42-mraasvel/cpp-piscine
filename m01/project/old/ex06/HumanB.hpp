#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

/*
Question: Why weapon pointer?

The constructor does not initialize weapon, therefore a pointer allows it to have NULL value
*/

class HumanB {

public:

	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon& weapon);
	void attack() const;

private:

	const std::string _name;
	Weapon *_weapon;

};

#endif /* HUMANB_HPP */
