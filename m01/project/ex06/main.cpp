#include <iostream>
#include "Karen.hpp"

int main(int argc, char *argv[]) {
	Karen karen;

	if (argc < 2) {
		std::cout << "Karen is unusually quiet" << std::endl;
	} else {
		karen.complain(argv[1]);
	}

	return 0;
}
