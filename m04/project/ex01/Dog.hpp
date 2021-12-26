#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Brain;

class Dog : public Animal {

/* Constructors / Destructors */

public:

	Dog();
	Dog(const Dog&);
	virtual ~Dog();

/* Operators */

	Dog& operator=(const Dog&);

/* Member Functions */

	virtual void makeSound() const;

private:

	Brain* brain;

};

#endif /* DOG_HPP */
