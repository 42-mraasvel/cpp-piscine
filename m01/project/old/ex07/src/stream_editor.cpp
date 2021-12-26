#include <iostream>
#include <sstream>
#include "stream_editor.hpp"

StreamEditor::StreamEditor() {}

StreamEditor::StreamEditor(std::string filename, std::string find, std::string replace) :
	_filename(filename), _find(find), _replace(replace) {

	_failed = false;
}

StreamEditor::~StreamEditor() {}

void StreamEditor::FileFindAndReplace(std::string filename, std::string find, std::string replace) {

	StreamEditor sed(filename, find, replace);
	sed._Replace();
}

void StreamEditor::_Replace() {
	std::string new_file = _GenerateReplacement();
	if (SedFailed()) {
		return;
	}
	_WriteToFile(new_file);
}

/*
Creates and returns an entire string of the new file with all replacements done
*/
std::string StreamEditor::_GenerateReplacement() {

	std::ifstream ifs;
	ifs.open(_filename, std::ios::in);
	if (!ifs.is_open()) {
		_Error("Failed to open file for reading: " + _filename);
		return std::string("");
	}

	std::ostringstream new_file;
	while (!ifs.eof()) {
		std::string line;
		std::getline(ifs, line);
		_FindReplaceString(line);
		if (ifs.eof()) {
			new_file << line;
		} else {
			new_file << line << std::endl;
		}
	}

	ifs.close();
	return new_file.str();

}

/*
Replaces all occurances of _find with _replace in line
*/
void StreamEditor::_FindReplaceString(std::string& str) const {

	size_t index = 0;
	while (true) {
		index = str.find(_find, index);
		if (index == std::string::npos) {
			break;
		}
		str.replace(index, _find.length(), _replace);
		index += _replace.length();
	}
}

void StreamEditor::_WriteToFile(std::string& new_file) {
	std::ofstream ofs;
	std::string outfile = _filename + ".replace";
	ofs.open(outfile, std::ios::out | std::ios::trunc);
	if (!ofs.is_open()) {
		_Error("Failed to open file for writing: " + outfile);
		return;
	}
	ofs << new_file;
	ofs.close();
}

void StreamEditor::_Error(std::string msg) {
	std::cerr << msg << std::endl;
	_failed = true;
}

bool StreamEditor::SedFailed() const {
	return _failed;
}
