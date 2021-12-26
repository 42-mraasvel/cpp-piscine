#include <iostream>
#include <fstream>
#include "stream_editor.hpp"


/* Input: ./replace FILE S1 S2 */
int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return 0;
	}

	StreamEditor::FileFindAndReplace(argv[1], argv[2], argv[3]);

	return 0;
}
