#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

// Forward declaration instead of header inclusion
class Enemy;
class AWeapon;

class Character {

private:

	Character();

	std::string name;
	int action_points;
	AWeapon *weapon;

	static const int MaxAP;

public:

	Character(std::string const& name);
	Character(const Character& from);
	Character& operator=(const Character& rhs);
	~Character();

	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
	
	std::string const& getName() const;
	const AWeapon *getWeapon() const;
	int getAP() const;

};

std::ostream& operator<<(std::ostream& out, const Character& rhs);

#endif /* CHARACTER_HPP */
