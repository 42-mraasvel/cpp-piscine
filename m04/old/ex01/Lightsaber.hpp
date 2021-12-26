#ifndef LIGHTSABER_HPP
# define LIGHTSABER_HPP

# include "AWeapon.hpp"

class Lightsaber : public AWeapon {

public:

	Lightsaber();
	Lightsaber(const Lightsaber& from);
	~Lightsaber();

	virtual void attack() const;

private:

	Lightsaber& operator=(const Lightsaber& rhs);

};

#endif /* LIGHTSABER_HPP */
