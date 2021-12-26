#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* Non-member attributes */

const int Fixed::_fractional_bits = 8;


/* Constructors / Destructors */

Fixed::Fixed() 
	: _value(0) {
}

Fixed::Fixed(const Fixed& from) {
	*this = from;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int n) {
	_value = n << _fractional_bits;
}

// n * 2^fractional_bits
Fixed::Fixed(const float n) : _value(n) {
	_value = roundf(n * (float)(1 << _fractional_bits));
}


/* Operator Overloading */

Fixed& Fixed::operator=(const Fixed& rhs) {

	if (this == &rhs) {
		return *this;
	}

	_value = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}


/* Comparisons */

bool Fixed::operator>(const Fixed& rhs) const {
	return _value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
	return _value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return _value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return _value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
	return _value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return _value != rhs.getRawBits();
}

/* Arithmetic */

const Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed x;
	x.setRawBits(_value + rhs.getRawBits());
	return x;
}

const Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed x;
	x.setRawBits(_value - rhs.getRawBits());
	return x;
}

/*

_value = some value x * 2^n

Initial multiplication:
(x * 2^n) * (y * 2^n) = (xy * 2^2n)

result wanted: (x * y) * (2^n): so we divide by (2^n)
We do that by shifting to the right by n after multiplication

Problems:

	Overflow in initial multiplication (x * y)
		(meaning even though both numbers and the result fit in Fixed Point format, we can't get an accurate result like this)
	Underflow in shift (losing precision)

*/

const Fixed Fixed::operator*(const Fixed &rhs) const {

	Fixed x;

	//! Very prone to overflow imo
	x.setRawBits( ( _value * rhs._value )  >> _fractional_bits );

	return x;

	// Failsafe, slower, safer, easier
	return Fixed ( toFloat() * rhs.toFloat() );
}

/*

_value = some value x * 2^_fractional_bits
so (x * 2^n) / (y * 2^n) = (x / y)
But since we want the result in fixed point format we have to multiply the result by (2^n)
Meaning we shift left by _fractional_bits

Why before the division instead of after division?
- To prevent integer division losing precision
Dangers: Overflow prone while shifting (We lose n significant bits by shifting to the left)

*/

const Fixed Fixed::operator/(const Fixed &rhs) const {

	Fixed x;

	x.setRawBits( (_value << _fractional_bits) / (rhs._value) );
	return x;

	// Failsafe, slower, safer, easier
	return Fixed ( toFloat() / rhs.toFloat() );
}

/*
*crement
Smallest possible value (epsilon) in Fixed Point format = rawBits(1);
Equal to 1 / 2^n where n is the number of fractional bits
*/

const Fixed& Fixed::operator++() {
	this->_value += 1;
	return *this;
}

const Fixed Fixed::operator++(int) {
	Fixed x;
	x.setRawBits(_value);
	this->_value += 1;
	return x;
}

const Fixed& Fixed::operator--() {
	this->_value -= 1;
	return *this;
}

const Fixed Fixed::operator--(int) {
	Fixed x;
	x.setRawBits(_value);
	this->_value -= 1;
	return x;
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


/* Static Member Functions */

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b) {
		return a;
	}

	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b) {
		return a;
	}

	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b) {
		return a;
	}

	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b) {
		return a;
	}

	return b;
}
