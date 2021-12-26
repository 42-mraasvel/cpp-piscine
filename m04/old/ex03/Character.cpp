#include "AMateria.hpp"
#include "Character.hpp"

Character::Character() {
	clearMateria();
}

Character::Character(const std::string& name)
	: name(name) {
	clearMateria();
}

Character::Character(const Character& from) {
	clearMateria();
	*this = from;
}

Character::~Character() {
	deleteMateria();
}


Character& Character::operator=(const Character& rhs) {
	if (this == &rhs) {
		return *this;
	}

	deleteMateria();
	for (int i = 0; i < 4; i++) {
		if (rhs.materia[i]) {
			materia[i] = rhs.materia[i]->clone();
		}
	}

	return *this;
}

std::string const& Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (materia[i] == 0) {
			materia[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		materia[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3 && materia[idx]) {
		materia[idx]->use(target);
	}
}

// Set all pointers to NULL
void Character::clearMateria() {
	for (int i = 0; i < 4; i++) {
		materia[i] = 0;
	}
}

// Delete all pointers and set to NULL
void Character::deleteMateria() {
	for (int i = 0; i < 4; i++) {
		if (materia[i]) {
			delete materia[i];
			materia[i] = 0;
		}
	}
}
