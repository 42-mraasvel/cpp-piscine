#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
	: size(0) {
}

MateriaSource::MateriaSource(const MateriaSource& from) {
	*this = from;
}

MateriaSource::~MateriaSource() {
	clear();
}


MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this == &rhs) {
		return *this;
	}

	clear();
	for (int i = 0; i < rhs.size; i++) {
		materia[i] = rhs.materia[i]->clone();
		size++;
	}

	return *this;
}

void MateriaSource::learnMateria(AMateria* src) {
	if (size == 4 || src == 0) {
		return;
	}
	materia[size] = src;
	size++;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < size; i++) {
		if (materia[i]->getType() == type) {
			return materia[i]->clone();
		}
	}
	return 0;
}

void MateriaSource::clear() {
	for (int i = 0; i < size; i++) {
		delete materia[i];
	}
	size = 0;
}
