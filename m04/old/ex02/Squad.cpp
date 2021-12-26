#include "Squad.hpp"

Squad::Squad()
	: size(0), nmemb(0), table(0) {}

Squad::Squad(const Squad& from)
	: size(from.size), nmemb(0) {
	table = new ISpaceMarine*[from.size];
	for (int i = 0; i < from.nmemb; i++) {
		table[i] = from.table[i]->clone();
		nmemb++;
	}
}

Squad::~Squad() {
	clear();
}

Squad& Squad::operator=(const Squad& rhs) {
	if (this == &rhs) {
		return *this;
	}

	clear();
	table = new ISpaceMarine*[size];
	size = rhs.size;
	for (int i = 0; i < rhs.nmemb; i++) {
		table[i] = rhs.table[i]->clone();
		nmemb++;
	}

	return *this;
}

int Squad::getCount() const {
	return nmemb;
}

ISpaceMarine* Squad::getUnit(int index) const {
	if (index < 0 || index > nmemb - 1) {
		return 0;
	}
	return table[index];
}

int Squad::push(ISpaceMarine* new_entry) {
	if (unitInSquad(new_entry)) {
		return nmemb;
	}
	ensureCapacity();
	table[nmemb] = new_entry;
	nmemb += 1;
	return nmemb;
}

void Squad::ensureCapacity() {
	if (size == nmemb) {
		ISpaceMarine **temp = table;
		if (size == 0) {
			size = 1;
		}
		table = new ISpaceMarine*[size * 2];
		size *= 2;
		for (int i = 0; i < nmemb; i++) {
			table[i] = temp[i];
		}
	}
}

void Squad::clear() {
	for (int i = 0; i < nmemb; i++) {
		delete table[i];
	}
	delete [] table;
	size = 0;
	nmemb = 0;
	table = 0;
}

bool Squad::unitInSquad(ISpaceMarine* entry) {
	if (entry == 0) {
		return true;
	}
	for (int i = 0; i < nmemb; i++) {
		if (table[i] == entry) {
			return true;
		}
	}
	return false;
}
