#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria {

protected:

	AMateria();

	const std::string _type;
	unsigned int _xp;

public:

	AMateria(std::string const& type);
	AMateria(const AMateria& from);
	AMateria& operator=(const AMateria& rhs);
	virtual ~AMateria();

	std::string const& getType() const; // Returns the Materia's type
	unsigned int getXP() const; // Returns the Materia's XP

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif /* AMATERIA_HPP */
