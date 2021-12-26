#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# ifndef MAX_MATERIA
# define MAX_MATERIA 4
# endif /* MAX_MATERIA */

class Character : public ICharacter {
public:
	Character(const std::string& name);
	Character(const Character& from);
	virtual ~Character();

	Character& operator=(const Character& rhs);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	Character();

	std::string name;
	AMateria* materia[MAX_MATERIA];
};

#endif /* CHARACTER_HPP */
