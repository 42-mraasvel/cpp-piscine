#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

/* Constructors / Destructors */

public:

	WrongCat();
	WrongCat(const WrongCat&);
	virtual ~WrongCat();

/* Operators */

	WrongCat& operator=(const WrongCat&);

/* Member Functions */

	void makeSound() const;

};

#endif /* WRONGCAT_HPP */
