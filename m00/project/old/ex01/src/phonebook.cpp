#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

// Default Constructor
Phonebook::Phonebook(void) : max_size(8), size(0) {}

// Destructor
Phonebook::~Phonebook(void) {}

void Phonebook::Prompt(void) {

	std::cout << "Options: EXIT | ADD | SEARCH" << std::endl;
	while (!std::cin.eof()) {

		std::cout << "Query: ";
		std::string cmd;
		std::getline(std::cin, cmd);

		if (std::cin.eof()) {
			break ;
		}

		if (cmd == "EXIT") {
			return ;
		} else if (cmd == "ADD") {
			Add();
		} else if (cmd == "SEARCH") {
			Search();
		}
	}
	std::cout << std::endl;
}

/*
Read contact info
Add new contact to phonebook
Increment size by 1
*/

void Phonebook::Add(void) {
	if (size == max_size) {
		std::cout << "Maximum phonebook capacity reached." << std::endl;
		return;
	}

	Contact new_contact(size);

	if (std::cin.eof()) {
		return;
	} else if (new_contact.GetTotal() == 0) {
		std::cout << "Did not add contact due to empty fields" << std::endl;
	} else {
		contacts[size] = new_contact;
		size += 1;
		std::cout << "Contact added successfully" << std::endl;
	}


}

/*
Class instance should not be changed from this function, so it's marked as const
*/

void Phonebook::Search(void) const {

	if (size == 0) {
		std::cout << "No contacts available" << std::endl;
		return;
	}

	//! Formatted output
	std::cout	<< std::setw(10) << "index" << '|' \
				<< std::setw(10) << "first name" << '|' \
				<< std::setw(10) << "last name" << '|' \
				<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < size; i++) {
		contacts[i].PrintColumn();
	}


	std::string index;
	std::cout << "Enter index: ";
	std::getline(std::cin, index);

	if (std::cin.eof()) {
		return;
	} else if (ValidIndex(index)) {
		contacts[index[0] - '0'].PrintInfo();
	} else {
		std::cerr << "Invalid index, please try again" << std::endl;
	}
}

/* Check if index is usable in our phonebook */
bool Phonebook::ValidIndex(std::string index) const {

	if (index.length() != 1 || !(index[0] >= '0' && index[0] < (size + '0'))) {
		return false;
	} else {
		return true;
	}
}
