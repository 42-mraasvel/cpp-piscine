#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {

	// Incrementing lowers to value to 0, throwing an exception
	Bureaucrat a("A Name", 1);
	try {
		a.incrementGrade();
	} catch (std::exception& e) {
		std::cout << a;
		std::cout << e.what() << std::endl << std::endl;
	}

	// Decrementing twice raises the value above 150 (min), throwing an exception
	Bureaucrat b("Maarten", 149);
	std::cout << b;
	try {
		b.decrementGrade();
		b.decrementGrade();
	} catch (std::exception& e) {
		std::cout << b;
		std::cout << e.what() << std::endl << std::endl;
	}

	// Initialize with invalid values: throws exception
	try {
		Bureaucrat c("C", 151);
		std::cout << c;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat d("D", 0);
		std::cout << d;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
