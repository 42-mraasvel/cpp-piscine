#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

/* Default Constructor */
Contact::Contact(void) : _index(-1), _total(0) {}

/* Initialized Constructor, reads all input */
Contact::Contact(int index) : _index(index), _total(0) {
	_first_name = _GetInfoString("first name");
	_last_name = _GetInfoString("last name");
	_nickname = _GetInfoString("nickname");
	_login = _GetInfoString("login");
	_postal_address = _GetInfoString("postal address");
	_email_address = _GetInfoString("email address");
	_birthday_date = _GetInfoString("birthday date");
	_favorite_meal = _GetInfoString("favorite meal");
	_underwear_color = _GetInfoString("underwear color");
	_darkest_secret = _GetInfoString("darkest secret");
}

Contact::~Contact(void) {}

std::string Contact::_GetInfoString(std::string name) {

	std::string dst;
	if (std::cin.eof()) {
		return dst;
	}

	std::cout << "Please enter your " << name << ": ";
	std::getline(std::cin, dst);

	if (dst.length() > 0) {
		_total += 1;
	}

	return dst;
}

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
	_PrintInfoDictFormat("login", _login);
	_PrintInfoDictFormat("postal address", _postal_address);
	_PrintInfoDictFormat("email address", _email_address);
	_PrintInfoDictFormat("phone number", _phone_number);
	_PrintInfoDictFormat("birthday date", _birthday_date);
	_PrintInfoDictFormat("favorite meal", _favorite_meal);
	_PrintInfoDictFormat("underwear color", _underwear_color);
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

int Contact::GetTotal(void) const {
	return _total;
}
