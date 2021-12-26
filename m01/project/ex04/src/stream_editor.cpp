#include <iostream>
#include <fstream>
#include "stream_editor.hpp"

/*
Small wrapper for starting sed
*/
void StreamEditor::Sed(const std::string& filename, const std::string& find, const std::string& replace) {
	StreamEditor sed(filename, find, replace);
	sed.Execute();
}

/*
Constructor, Destructor
*/

StreamEditor::StreamEditor(const std::string& filename, const std::string& find, const std::string& replace)
	: _failed(false), _filename(filename), _find(find), _replace(replace) {}

StreamEditor::~StreamEditor() {}


/* Methods */

void StreamEditor::Execute() {

	if (_find.length() == 0 || _replace.length() == 0) {
		_failed = true;
		std::cerr << "sed: invalid length for strings" << std::endl;
		return;
	}

	if (_OpenFiles() == ERROR) {
		_failed = true;
		return;
	}

	_ReplaceFile();

	_src_file.close();
	_dst_file.close();
}

enum SedEnums StreamEditor::_OpenFiles() {

	_src_file.open(_filename.c_str(), std::ios_base::in);
	if (!_src_file.is_open()) {
		std::cerr << "Failed to open: " << _filename << std::endl;
		return ERROR;
	}

	std::string dst_filename = _filename + ".replace";
	_dst_file.open(dst_filename.c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!_dst_file.is_open()) {
		_src_file.close();
		std::cerr << "Failed to open: " << _filename << ".replace" << std::endl;
		return ERROR;
	}
	return OK;
}

/*
Read src file line by line
Create a new line with the replacement, to write to the outfile
*/
void StreamEditor::_ReplaceFile() {
	std::string line;
	while (!_src_file.eof()) {
		std::getline(_src_file, line);
		_dst_file << _ReplacedLine(line);
		if (_src_file.eof()) {
			return;
		}
		_dst_file << std::endl;
	}
}

/*
Create new line, every time an occurance of _find is found, add _replace instead

Example:

String('123 Bla 123'), find('Bla'), Replace('Replace')

1. string.find returns index of B initially
2. take the substr '123 ', then add Replace to the new_line
3. Skip Bla and search for another occurance, if present, otherwise add the rest of the line

*/
std::string StreamEditor::_ReplacedLine(const std::string& line) const {

	std::string new_line;
	size_t i = 0;
	size_t start = 0;

	while (i < line.length()) {
		i = line.find(_find, i);
		if (i == std::string::npos) {
			break;
		}

		new_line += line.substr(start, i - start) + _replace;
		i += _find.length();
		start = i;
	}
	new_line += line.substr(start);
	return new_line;
}

bool StreamEditor::Good() const {
	return _failed == false;
}
