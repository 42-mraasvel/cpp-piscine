#include <fstream>
#include <iostream>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

/*
std::cin.read() doesn't return on newline:
So in order to mimic CAT's behavior I only read 1 byte at the time
*/
static void ReadStdin() {
	char buffer;
	while (true) {
		std::cin.read(&buffer, 1);
		if (std::cin.eof()) {
			break;
		}
		std::cout.write(&buffer, 1);
	}
}

static void DisplayFile(const char *filename) {

	std::ifstream ifs;
	ifs.open(filename, std::ios::in | std::ios::binary);
	if (!ifs.is_open()) {
		std::cerr << "cat: " << filename << ": No such file or directory" << std::endl;
		return;
	}
	char buffer[BUFFER_SIZE];
	while (!ifs.eof()) {
		ifs.read(buffer, BUFFER_SIZE);
		std::cout.write(buffer, ifs.gcount());
	}
	ifs.close();
}

static void ReadFiles(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (std::string(argv[i]) == "-") {
			ReadStdin();
		} else {
			DisplayFile(argv[i]);
		}
	}
}

int main(int argc, char *argv[]) {

	if (argc == 1) {
		ReadStdin();
	} else {
		ReadFiles(argc, argv);
	}

	return 0;
}
