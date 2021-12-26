#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() 
	: _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& from) {
	std::cout << "Copy constructor called" << std::endl;
	*this = from;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& x) {
	std::cout << "Assignation operator called" << std::endl;

	if (this == &x) {
		return *this;
	}

	_value = x.getRawBits();
	return *this;
}

const int Fixed::_fractional_bits = 8;

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
