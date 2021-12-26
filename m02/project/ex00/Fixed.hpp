#ifndef FIXED_HPP
# define FIXED_HPP

/*

Resources

Orthodox Canonical Class Form / Coplien Form:

	https://www.francescmm.com/orthodox-canonical-class-form/

Floats:

	https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
	https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html
	https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

Fixed point:

	https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
	https://www.youtube.com/watch?v=IECKQ7pqUms

*/

class Fixed {

public:

	Fixed();
	Fixed(const Fixed& from);
	~Fixed();

	Fixed& operator=(const Fixed& x);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	static const int _fractional_bits;

	int _value;

};

#endif /* FIXED_HPP */
