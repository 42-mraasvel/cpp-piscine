#include <iostream>
#include "determine_type.hpp"
#include "converter.hpp"

static void PrintArgError() {
	std::cerr << "Invalid argument" << std::endl;
	std::cerr << "Usage: ./a.out [CHAR | INT | FLOAT | DOUBLE]" << std::endl;
}

static bool CheckArg(int argc, char *argv[]) {
	if (argc != 2) {
		return false;
	}
	std::string arg = argv[1];
	if (arg.length() == 0) {
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {

	if (!CheckArg(argc, argv)) {
		PrintArgError();
		return 0;
	}

	enum Type type = DetermineType(argv[1]);

	if (type == UNKNOWN) {
		std::cerr << "Unknown type" << std::endl;
		return 0;
	}

	Converter convert(argv[1], type);
	convert.Print();
	return 0;
}
