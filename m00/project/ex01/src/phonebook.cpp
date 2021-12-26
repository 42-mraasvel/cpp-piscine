#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

/* Constructors and operators */

Phonebook::Phonebook()
	: _MAX_SIZE(8), _size(0), _index(0) {}

/* Methods */

void Phonebook::Prompt() {

	std::cout << "Options: ADD | SEARCH | EXIT" << std::endl;
	while (!std::cin.eof()) {

		std::string query;
		std::cout << "Query: ";
		std::getline(std::cin, query);

		if (std::cin.eof() || query == "EXIT") {
			break;
		} else if (query == "ADD") {
			_AddEntry();
		} else if (query == "SEARCH") {
			_SearchPhonebook();
		}
	}
	if (std::cin.eof()) {
		std::cout << std::endl;
	}
}


void Phonebook::_AddEntry() {
	Contact new_entry;
	new_entry.GetContactInfo();
	if (std::cin.eof()) {
		return;
	}

	if (new_entry.IsEmpty()) {
		std::cout << "Didn't add contact because of empty field" << std::endl;
		return;
	}

	if (_index == _MAX_SIZE) {
		_index = 0;
	}
	new_entry.SetIndex(_index);
	_contacts[_index] = new_entry;
	if (_size != _MAX_SIZE) {
		_size++;
	}
	std::cout << "Added new entry at position |" << _index << "|" << std::endl;
	_index++;
}


void Phonebook::_SearchPhonebook() {

	if (_size == 0) {
		std::cout << "No contacts available" << std::endl;
		return;
	}

	//! Formatted output
	std::cout	<< std::setw(10) << "index" << '|' \
				<< std::setw(10) << "first name" << '|' \
				<< std::setw(10) << "last name" << '|' \
				<< std::setw(10) << "nickname" << std::endl;
	for (size_t i = 0; i < _size; i++) {
		_contacts[i].PrintColumn();
	}


	std::string index;
	std::cout << "Enter index: ";
	std::getline(std::cin, index);

	if (std::cin.eof()) {
		return;
	} else if (_ValidIndex(index)) {
		_contacts[index[0] - '0'].PrintInfo();
	} else {
		std::cerr << "Invalid index, please try again" << std::endl;
	}

}

/* Check if index is usable in our phonebook */
bool Phonebook::_ValidIndex(std::string index) const {

	if (index.length() != 1 || !(index[0] >= '0' && (size_t)index[0] < (_size + '0'))) {
		return false;
	} else {
		return true;
	}
}
