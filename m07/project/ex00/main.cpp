#include <iostream>
#include <iomanip>
#include "whatever.hpp"

/*
I think something like this was in the eval sheet last time
*/
class ExampleClass {
public:
	ExampleClass(int n) : n(n) {}

	bool operator==(const ExampleClass& rhs) const { return n == rhs.n; }
	bool operator<=(const ExampleClass& rhs) const { return n <= rhs.n; }
	bool operator>=(const ExampleClass& rhs) const { return n >= rhs.n; }
	bool operator<(const ExampleClass& rhs) const { return n < rhs.n; }
	bool operator>(const ExampleClass& rhs) const { return n > rhs.n; }
	bool operator!=(const ExampleClass& rhs) const { return n != rhs.n; }

	int get() const {
		return n;
	}

private:
	int n;
};

std::ostream& operator<<(std::ostream& out, const ExampleClass& rhs) {
	out << rhs.get();
	return out;
}

void ExampleTests() {
	std::cout << " ** EXAMPLE TESTS ** " << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void ExtraTests() {
	std::cout << std::endl << " ** EXTRA TESTS ** " << std::endl;

	float x = 42.42;
	float y = 420.42;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "(x, y) = (" << x << ", " << y << ")" << std::endl;
	::swap<float>(x, y); // Explicit type
	std::cout << "After swap(x, y) : (" << x << ", " << y << ")" << std::endl;
	::swap(x, y); // Implicit type to swap back

	std::cout << "max(" << x << ", " << y << ") = " << ::max<float>(x, y) << std::endl;
	std::cout << "min(" << x << ", " << y << ") = " << ::min<float>(x, y) << std::endl;
}

int main( void ) {
	ExampleTests();
	ExtraTests();

	ExampleClass a(5);
	ExampleClass b(7);

	std::cout << "a(" << a << "), b(" << b << ')' << std::endl;
	::swap(a, b);
	std::cout << "a(" << a << "), b(" << b << ')' << std::endl;

	std::cout << "min(" << a << ", " << b << ") = " << ::min(a, b) << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << ::max(a, b) << std::endl;

	return 0;
}
