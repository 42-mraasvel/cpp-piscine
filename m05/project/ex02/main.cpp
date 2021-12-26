#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void TestShrubbery() {

	std::cout << " ** SHRUBBERY FORM TESTS ** " << std::endl;

	Bureaucrat high("Greatest Bureaucrat", 137);
	Bureaucrat low("Lowly Bureaucrat", 138);
	Bureaucrat lower("Lowlier Bureaucrat", 146);

	ShrubberyCreationForm scf("SHRUB");

	std::cout << high << low << lower << scf << std::endl;

	lower.signForm(scf);
	low.signForm(scf);

	std::cout << std::endl;

	lower.executeForm(scf);
	low.executeForm(scf);
	high.executeForm(scf);
}

void TestRoboto() {

	std::cout << " ** ROBOTO FORM TESTS ** " << std::endl;

	Bureaucrat high("Greatest Bureaucrat", 45);
	Bureaucrat low("Lowly Bureaucrat", 72);
	Bureaucrat lower("Lowlier Bureaucrat", 73);

	RobotomyRequestForm rrf("ROLO");
	std::cout << high << low << lower << rrf << std::endl;

	lower.signForm(rrf);
	low.signForm(rrf);
	high.signForm(rrf);

	std::cout << std::endl;

	low.executeForm(rrf);
	high.executeForm(rrf);
	high.executeForm(rrf);
}

void TestPresidential() {

	std::cout << " ** PRESIDENTIAL FORM TESTS ** " << std::endl;

	Bureaucrat high("Greatest Bureaucrat", 5);
	Bureaucrat low("Lowly Bureaucrat", 25);
	Bureaucrat lower("Lowlier Bureaucrat", 26);

	PresidentialPardonForm ppf("PRESIDENT'S BEST FRIEND");
	std::cout << high << low << lower << ppf << std::endl;

	high.executeForm(ppf);

	lower.signForm(ppf);
	low.signForm(ppf);
	high.signForm(ppf);

	std::cout << std::endl;

	lower.executeForm(ppf);
	low.executeForm(ppf);
	high.executeForm(ppf);
}

int main(void) {

	srand(time(0)); // For the RobotomyRequestForm 50/50

	TestShrubbery();
	std::cout << std::endl << std::endl;
	TestRoboto();
	std::cout << std::endl << std::endl;
	TestPresidential();

	return 0;
}
