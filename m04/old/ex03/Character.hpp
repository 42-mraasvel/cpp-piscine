#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

public:

	Character(const std::string& name);
	Character(const Character& from);
	~Character();

	Character& operator=(const Character& rhs);

	virtual std::string const& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:

	Character();

	void clearMateria();
	void deleteMateria();

	AMateria* materia[4];
	std::string name;

};

#endif /* CHARACTER_HPP */
