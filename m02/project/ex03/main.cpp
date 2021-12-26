#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

/*

	Triangle: (2, 2), (3, 5), (5, 3)

	7 |
	6 |
	5 |  .
	4 |
	3 |       .
	2 | .
	1 |____________
	0 1 2 3 4 5 6

*/

static void Tests(const Point& a, const Point& b, const Point& c) {
	const Point points[] = {
		Point(3, 3),
		Point(6, 1),
		Point(5, 2),
		Point(5.9, 2),
		Point(5.9, 1),
		Point(3, 4.9),
		Point(3, 5.1),
		Point(1000, 500.25),
		a,
		b,
		c
	};

	const size_t NUM_POINTS = sizeof(points) / sizeof(Point);

	std::cout << "Triangle: " << a << b << c << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < NUM_POINTS; i++) {

		bool result = bsp(a, b, c, points[i]);

		std::cout << points[i] << " in T: " << std::boolalpha << result << std::endl;
	}
}

int main(void) {

	const Point a(2, 2);
	const Point b(3, 5);
	const Point c(5, 3);

	Tests(a, b, c);
	
	return 0;
}
