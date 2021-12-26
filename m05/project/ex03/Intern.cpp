#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& from) {
	(void)from;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

/*
Using array of strings and ENUMS to find type needed

Returns NULL if unknown form name is given
Caller expected to delete return
*/
Form* Intern::makeForm(const std::string& form_name, const std::string& target) const {

	static std::string form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	enum FormNames result = UNKNOWN;

	for (int i = 0; i < (int)UNKNOWN; i++) {
		if (form_name == form_names[i]) {
			result = (enum FormNames)i;
			break;
		}
	}

	Form* form;
	switch(result) {
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw UnknownFormException();
	}
	std::cout << "Intern creates " << *form;
	return form;
}

const char* Intern::UnknownFormException::what() const throw() {
	return "unknown form";
}
