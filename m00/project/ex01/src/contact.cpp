#include "contact.hpp"
#include <iostream>
#include <iomanip>

/* Constructors and overloads */

Contact::Contact() : _total_fields(0), _index(-1) {}

/* Methods */

void Contact::SetIndex(size_t index) {
	_index = index;
}

bool Contact::IsEmpty() const {
	return _total_fields == 0;
}

void Contact::_GetString(std::string& dst, const std::string& query) {

	if (std::cin.eof()) {
		return;
	}

	std::cout << "Please enter your " << query << ": ";
	std::getline(std::cin, dst);
	if (dst.length() > 0) {
		_total_fields += 1;
	}
}

void Contact::GetContactInfo() {
	_GetString(_first_name, "first name");
	_GetString(_last_name, "last name");
	_GetString(_nickname, "nickname");
	_GetString(_phone_number, "phone number");
	_GetString(_darkest_secret, "darkest secret");
}

/* Printing, Output */

void Contact::_PrintStringFormat(std::string content, int w) const {
	if (content.length() > (size_t)w) {
		std::cout << content.substr(0, w - 1) << '.';
	} else {
		std::cout << std::setw(w) << content;
	}
}

void Contact::_PrintInfoDictFormat(std::string a, std::string b) const {
	_PrintStringFormat(a, 15);
	std::cout << " : " << b << std::endl;
}

void Contact::PrintInfo(void) const {
	_PrintInfoDictFormat("first name", _first_name);
	_PrintInfoDictFormat("last name", _last_name);
	_PrintInfoDictFormat("nickname", _nickname);
	_PrintInfoDictFormat("phone number", _phone_number);
	_PrintInfoDictFormat("darkest secret", _darkest_secret);
}

void Contact::PrintColumn(void) const {

	std::cout << std::setw(10) << _index << '|';
	_PrintStringFormat(_first_name, 10);
	std::cout << '|';
	_PrintStringFormat(_last_name, 10);
	std::cout << '|';
	_PrintStringFormat(_nickname, 10);
	std::cout << std::endl;
}
