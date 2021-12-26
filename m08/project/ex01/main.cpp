#include <climits>
#include <iostream>
#include "span.hpp"

void ExampleTests() {
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << " ** EXAMPLE ** " << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void BigTest() {
	std::cout << " ** BIG TEST ** " << std::endl;
	Span sp(100000);

	sp.addRange(1, 10000);

	std::cout << "Total ints(" << sp.size() << ")" << std::endl;

	// Add min and max int
	sp.addNumber(INT_MAX);
	sp.addNumber(INT_MIN);

	sp.addRange(10001, 50000);

	std::cout << "Total ints(" << sp.size() << ")" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void ExceptionTest() {
	std::cout << " ** EXCEPTION ** " << std::endl;
	Span sp(1);
	sp.addNumber(1);

	try {
		sp.addNumber(2);
	} catch (const std::exception& e) {
		std::cout << "1: caught: " << e.what() << std::endl;
	}

	try {
		sp.shortestSpan();
	} catch (const std::exception& e) {
		std::cout << "2: caught: " << e.what() << std::endl;
	}

	try {
		sp.longestSpan();
	} catch (const std::exception& e) {
		std::cout << "3: caught: " << e.what() << std::endl;
	}
}

int main(void) {


	ExampleTests();
	BigTest();
	ExceptionTest();

	Span s(20);

	s.addNumber(-5);
	s.addNumber(-5);
	s.addRange(7);
	std::cout << s.shortestSpan() << std::endl;
	return 0;
}
