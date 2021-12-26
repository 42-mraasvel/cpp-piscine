#include "Point.hpp"

/* Constructors / Destructors */

Point::Point()
	: x(), y() {}

Point::Point(const float x, const float y)
	: x(x), y(y) {}

Point::Point(const Fixed& x, const Fixed& y)
	: x(x), y(y) {}

Point::Point(const Point& from)
	: x(from.GetX()), y(from.GetY()) {
}

Point::~Point() {}

/* Operator Overloading */

Point& Point::operator=(const Point& rhs) {

	if (this == &rhs) {
		return *this;
	}

	return *this;
}

Point Point::operator+(const Point& rhs) const {
	return Point (x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Point& rhs) const {
	return Point (x - rhs.x, y - rhs.y);
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
	out << "(" << p.GetX() << ", " <<  p.GetY() << ")";
	return out;
}

/* Methods */

const Fixed& Point::GetX() const {
	return x;
}

const Fixed& Point::GetY() const {
	return y;
}
