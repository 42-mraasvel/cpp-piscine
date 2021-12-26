#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*

Resources used

	https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e

*/

class Fixed {

public:

	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& from);
	~Fixed();

	Fixed& operator=(const Fixed& x);

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
