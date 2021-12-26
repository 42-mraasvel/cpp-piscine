#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: size(0) {}

MateriaSource::MateriaSource(const MateriaSource& from)
	: size(from.size) {
	for (int i = 0; i < from.size; i++) {
		materia[i] = from.materia[i]->clone();
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < size; i++) {
		delete materia[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this == &rhs) {
		return *this;
	}

	for (int i = 0; i < rhs.size; i++) {
		if (i < size) {
			delete materia[i];
		}
		materia[i] = rhs.materia[i]->clone();
	}
	size = rhs.size;
	return *this;
}


void MateriaSource::learnMateria(AMateria* src) {
	if (size == MAX_MATERIA || src == NULL) {
		return;
	}

	materia[size] = src;
	size++;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < size; i++) {
		if (type == materia[i]->getType()) {
			return materia[i]->clone();
		}
	}
	return NULL;
}
