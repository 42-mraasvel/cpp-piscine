#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {

	srand(time(0)); // For the RobotomyRequestForm 50/50

	Intern maarten;
	Bureaucrat allmight("ALL MIGHT", 1);


	Form* scf = maarten.makeForm("shrubbery creation", "SHRUB");
	allmight.signForm(*scf);
	allmight.executeForm(*scf);
	delete scf;

	std::cout << std::endl;

	Form* rrf = maarten.makeForm("robotomy request", "Bender");
	allmight.signForm(*rrf);
	allmight.executeForm(*rrf);
	delete rrf;

	std::cout << std::endl;

	Form* ppf = maarten.makeForm("presidential pardon", "Priem");
	allmight.signForm(*ppf);
	allmight.executeForm(*ppf);
	delete ppf;

	std::cout << std::endl;


	std::cout << "TESTING INVALID FORM:" << std::endl;
	// Testing invalid form, should return a NULL POINTER
	try {
		Form* unknown = maarten.makeForm("random string", "Bender");
		std::cout << "created form: " << unknown->getName() << std::endl;
		delete unknown;
	} catch (const std::exception& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	return 0;
}
