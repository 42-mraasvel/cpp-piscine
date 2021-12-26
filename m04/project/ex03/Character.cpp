#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name)
	: name(name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		materia[i] = NULL;
	}
}

Character::Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		materia[i] = NULL;
	}
}

/* Deep Copy copy constructor by using clone */
Character::Character(const Character& from)
	: name(from.getName()) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (from.materia[i]) {
			materia[i] = from.materia[i]->clone();
		} else {
			materia[i] = NULL;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (materia[i]) {
			delete materia[i];
		}
	}
}

/* Deep Copy by cloning all materia, and deleting own */
Character& Character::operator=(const Character& rhs) {
	if (this == &rhs) {
		return *this;
	}

	name = rhs.getName();
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (materia[i]) {
			delete materia[i];
			materia[i] = NULL;
		}

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
	int index = -1;
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (materia[i] == m) {
			return;
		} else if (materia[i] == NULL && index == -1) {
			index = i;
		}
	}

	if (index != -1) {
		// This ensures we only equip a materia that isn't equipped yet
		materia[index] = m;
	}
}

/* Subject: Don't Delete */
void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_MATERIA) {
		materia[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= MAX_MATERIA || materia[idx] == NULL) {
		return;
	}

	materia[idx]->use(target);
}
