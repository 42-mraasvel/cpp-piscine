#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& from);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& rhs);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const& type);

private:

	void clear();

	AMateria* materia[4];
	int size;

};

#endif /* MATERIASOURCE_HPP */
