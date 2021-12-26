#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* Non-member attributes */

const int Fixed::_fractional_bits = 8;


/* Constructors / Destructors */

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

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractional_bits;
}

// n * 2^fractional_bits
Fixed::Fixed(const float n) : _value(n) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (float)(1 << _fractional_bits));
}


/* Operator Overloading */

Fixed& Fixed::operator=(const Fixed& x) {
	std::cout << "Assignation operator called" << std::endl;

	if (this == &x) {
		return *this;
	}

	_value = x.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}


/* Methods */

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

// value / 2^fractional_bits
float Fixed::toFloat(void) const {
	return 1.f * _value / (float)(1 << _fractional_bits);
}

int Fixed::toInt(void) const {
	return _value >> _fractional_bits;
}
