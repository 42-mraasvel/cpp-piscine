#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon {

protected:

	AWeapon();
	AWeapon& operator=(const AWeapon& rhs);

	const std::string name;
	int apcost;
	int damage;

public:

	AWeapon(std::string const& name, int apcost, int damage);
	AWeapon(const AWeapon& from);
	virtual ~AWeapon();

	std::string const& getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

};

#endif /* AWEAPON_HPP */
