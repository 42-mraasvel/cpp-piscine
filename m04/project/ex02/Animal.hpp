#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

/* Constructors / Destructors */

public:

	Animal();
	Animal(const Animal&);
	virtual ~Animal();

/* Operators */

	Animal& operator=(const Animal&);

/* Member Functions */

	const std::string& getType() const;
	// Now it is an abstract class
	virtual void makeSound() const = 0;

protected:

	// Protected constructor for derived classes
	Animal(const std::string& type);

/* Attributes */

	std::string type;

};

#endif /* ANIMAL_HPP */
