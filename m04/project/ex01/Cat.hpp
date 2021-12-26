#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Brain;

class Cat : public Animal {

/* Constructors / Destructors */

public:

	Cat();
	Cat(const Cat&);
	virtual ~Cat();

/* Operators */

	Cat& operator=(const Cat&);

/* Member Functions */

	virtual void makeSound() const;

private:

/* Attributes */

	Brain *brain;

};

#endif /* CAT_HPP */
