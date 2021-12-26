#include <iostream>

static void PrintArgUppercase(std::string arg) {
	for (int i = 0; arg[i] != '\0'; i++) {
		std::cout << (char)toupper(arg[i]);
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			PrintArgUppercase(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
