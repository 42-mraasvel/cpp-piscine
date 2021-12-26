#include <iostream>
#include "Fixed.hpp"

void TestConst(const Fixed a, const Fixed b) {
	std::cout << "ConstMin(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "ConstMax(a, b): " << Fixed::max(a, b) << std::endl;
}

void Tests(Fixed a, Fixed b) {

	std::cout << std::endl;
	std::cout << "**OWN TESTS**" << std::endl;
	std::cout << "a: " << a << std::endl << "b: " << b << std::endl << std::endl;

	std::cout << a << " > " << b << " : " << std::boolalpha << (a > b) << std::endl;
	std::cout << a << " < " << b << " : " << std::boolalpha << (a < b) << std::endl;
	std::cout << a << " >= " << b << " : " << std::boolalpha << (a >= b) << std::endl;
	std::cout << a << " <= " << b << " : " << std::boolalpha << (a <= b) << std::endl;
	std::cout << a << " == " << b << " : " << std::boolalpha << (a == b) << std::endl;
	std::cout << a << " != " << b << " : " << std::boolalpha << (a != b) << std::endl;
	std::cout << std::endl;


	std::cout << a << " + " << b << " : " << (a + b) << std::endl;
	std::cout << a << " - " << b << " : " << (a - b) << std::endl;
	std::cout << a << " * " << b << " : " << (a * b) << std::endl;
	std::cout << a << " / " << b << " : " << (a / b) << std::endl;
	std::cout << std::endl;

	std::cout << "a: " << a << ", ++a: " << ++a << ", a: " << a << std::endl;
	std::cout << "a: " << a << ", a++: " << a++ << ", a: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "a: " << a << ", --a: " << --a << ", a: " << a << std::endl;
	std::cout << "a: " << a << ", a--: " << a-- << ", a: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;

	TestConst(a, b);

	std::cout << std::endl;
}

void ExampleTests(void) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}

int main(void) {

	Fixed a(3.5f);
	Fixed b(7.0f);

	Tests(a, b);
	ExampleTests();

	return 0;
}
