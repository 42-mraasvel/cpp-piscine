#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:

	Point();
	Point(const float x, const float y);
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& from);
	~Point();

	Point& operator=(const Point& rhs);
	Point operator+(const Point& rhs) const;
	Point operator-(const Point& rhs) const;

	const Fixed& GetX() const;
	const Fixed& GetY() const;

private:

	const Fixed x;
	const Fixed y;

};

std::ostream& operator<<(std::ostream& out, const Point& p);

#endif /* POINT_HPP */
