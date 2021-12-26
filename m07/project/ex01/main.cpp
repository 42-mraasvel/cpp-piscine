#include <iostream>
#include <string>
#include <cstdlib>
#include "iter.hpp"

/* Also similar to what was in the eval sheet */
class ExampleClass {
public:
	ExampleClass() : n(42) {}
	int get() const { return n; }

private:
	int n;
};

std::ostream& operator<<(std::ostream& out, const ExampleClass& rhs) {
	out << rhs.get();
	return out;
}


/* Function Template Example */
template <typename T>
void Print(const T& x) {
	std::cout << x << std::endl;
}

int main(void) {
	srand(time(0)); // for rand()
	int int_table[] = {0, 1, 2, 3, 4};

	size_t int_table_size = sizeof(int_table) / sizeof(int);

	std::cout << " PRINTING INTS " << std::endl;
	iter<int>(int_table, int_table_size, Print<int>);


	std::string str_table[] = {
		"one",
		"two",
		"three",
		"four",
		"five",
		"six"
	};

	size_t str_table_size = sizeof(str_table) / sizeof(std::string);
	std::cout << std::endl << " PRINTING STRINGS " << std::endl;
	iter<std::string>(str_table, str_table_size, Print<std::string>);

	std::cout << std::endl << " WITH CLASS TYPE " << std::endl;
	ExampleClass tab[5];
	iter<ExampleClass>(tab, 5, Print);

	return 0;
}
