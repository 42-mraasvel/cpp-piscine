#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*

Resources used

	https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e

	https://blog.veitheller.de/Fixed_Point_Division.html

*/

class Fixed {

public:

	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& from);
	~Fixed();

	Fixed& operator=(const Fixed& rhs);

	// Comparison operators
	bool operator>(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

	// Arithmetic Operators
	const Fixed operator+(const Fixed& rhs) const;
	const Fixed operator-(const Fixed& rhs) const;
	const Fixed operator*(const Fixed& rhs) const;
	const Fixed operator/(const Fixed& rhs) const;

	/* *crement operators */
	const Fixed& operator++();
	const Fixed operator++(int);
	const Fixed& operator--();
	const Fixed operator--(int);

	/* static member functions */

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	/* Methods */

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:

	static const int _fractional_bits;

	int _value;

};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif /* FIXED_HPP */
