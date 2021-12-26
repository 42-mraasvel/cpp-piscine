#include "Point.hpp"

/*

Determinant of a matrix, where the points represent the columns of the matrix:

m =	[ Ax, Bx ]
	[ Ay, By ]

det(m) = Ax * By - Ay * By

*/

Fixed Determinant(Point a, Point b) {
	return  a.GetX() * b.GetY() - a.GetY() * b.GetX();
}

/*

Point in triangle solution

	https://www.youtube.com/watch?v=HYAgJN3x4GA
	https://mathworld.wolfram.com/TriangleInterior.html

AP = A + c1 * W1 + c2 * W2

AKA:

APx = Ax + c1 * W1x + c2 * W2x
APy = Ay + c1 * W1y + c2 * W2y

Explanation:
Solve for b and a, substitute in other formula
Point P is expressed in the vectors AB and AC from Point A

*/

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	const Point v1 (b - a);
	const Point v2 (c - a);

	const Fixed c1 =  ( Determinant(point, v2) - Determinant(a, v2) ) / Determinant(v1, v2);
	const Fixed c2 =  ( Determinant(point, v1) - Determinant(a, v1) ) / Determinant(v2, v1);

	if (c1 >= Fixed(0) && c2 >= Fixed(0) && (c1 + c2) <= Fixed (1)) {
		return true;
	}

	return false;
}
