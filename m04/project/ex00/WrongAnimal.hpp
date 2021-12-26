#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

/* Constructors / Destructors */

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal&);
	virtual ~WrongAnimal();

/* Operators */

	WrongAnimal& operator=(const WrongAnimal&);

/* Member Functions */

	const std::string& getType() const;
	// This is no longer virtual;
	// Meaning the Animal::makeSound() method will be called from derived classes when using subtype polymorphism
	void makeSound() const;

protected:

	// Protected constructor for derived classes
	WrongAnimal(const std::string& type);

/* Attributes */

	std::string type;


};

#endif /* WRONGANIMAL_HPP */
