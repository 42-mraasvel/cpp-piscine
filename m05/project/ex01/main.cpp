#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void TestConstructor() {

	std::cout << " ** CONSTRUCTOR EXCEPTION TESTS ** " << std::endl;
	//! All invalid form constructors
	try {
		Form f("Form", 0, 1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f("Form", 1, 0);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f("Form", 151, 1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f("Form", 1, 151);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void) {

	TestConstructor();

	Bureaucrat b("Bob", 10);

	Form form_1("Form1", 1, 1);
	Form form_2("Form2", 10, 1);

	std::cout << b << form_1 << form_2;

	// 1 valid, 1 invalid
	b.signForm(form_1);
	b.signForm(form_2);

	std::cout << form_1 << form_2;

	Bureaucrat me("Maarten", 1);
	std::cout << std::endl << me;
	me.signForm(form_1);
	std::cout << form_1;
	std::cout << form_2;
	return 0;
}
