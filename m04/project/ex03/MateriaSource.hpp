#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# ifndef MAX_MATERIA
# define MAX_MATERIA 4
# endif /* MAX_MATERIA */

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource& from);
	virtual ~MateriaSource();

	MateriaSource& operator=(const MateriaSource& rhs);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);

private:
	int size;
	AMateria* materia[MAX_MATERIA];
};


#endif /* MATERIASOURCE_HPP */
