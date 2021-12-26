#include <string>
#include <iostream>

void memoryLeak()
{
	std::string* panther = new std::string("String panther");
	std::cout << *panther << std::endl;

	// The memory leak was new being used, and not being deleted
	delete panther;
}

/*
Remove comment around main and compile with following to check leaks:

clang++ -Wall -Wextra -Werror ex01.cpp
valgrind ./a.out
*/

/*
int main(void) {
	memoryLeak();
	return 0;
}
*/
