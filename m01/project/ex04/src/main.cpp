#include <iostream>
#include "stream_editor.hpp"

/* ./EXEC FILENAME FIND REPLACE */
int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cerr << "Invalid nuber of arguments" << std::endl;
		std::cerr << "Expected: [FILENAME] [FIND_STR] [REPLACE_STR]" << std::endl;
		return 1;
	} else {

		StreamEditor::Sed(argv[1], argv[2], argv[3]);
	}
	return 0;
}
