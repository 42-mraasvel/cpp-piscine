#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:

	PowerFist();
	PowerFist(const PowerFist& from);
	~PowerFist();

	virtual void attack() const;

private:

	PowerFist& operator=(const PowerFist& rhs);

};

#endif /* POWERFIST_HPP */
