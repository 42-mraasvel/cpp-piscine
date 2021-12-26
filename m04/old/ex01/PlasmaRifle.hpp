#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle& from);
	~PlasmaRifle();


	virtual void attack() const;

private:

	PlasmaRifle& operator=(const PlasmaRifle& rhs);

};

#endif /* PLASMARIFLE_HPP */
