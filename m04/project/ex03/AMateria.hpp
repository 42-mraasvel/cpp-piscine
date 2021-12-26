#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria {
protected:

	std::string type;

public:

/* Constructors/Destructors */
	AMateria(std::string const& type);
	AMateria();
	AMateria(const AMateria& from);
	virtual ~AMateria();

/* Operators */
	AMateria& operator=(const AMateria& rhs);

/* Member Functions */
	std::string const& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif /* AMATERIA_HPP */
