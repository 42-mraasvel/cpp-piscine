#include <iostream>
#include <iomanip>
#include <cmath>
#include "converter.hpp"

void Converter::PrintChar() const {
	if (isprint(c)) {
		std::cout << "char: '" << c << '\'' << std::endl;
	} else {
		std::cout << "char: " << "Non displayable" << std::endl;
	}
}

void Converter::PrintInt() const {
	std::cout << "int: " << n << std::endl;
}

void Converter::PrintFloat() const {
	if (f == INFINITY && f > 0) {
		std::cout << "float: +" << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void Converter::PrintDouble() const {
	if (d == INFINITY && d > 0) {
		std::cout << "double: +" << std::fixed << std::setprecision(1) << d << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}

void Converter::PrintImpossible(const std::string& prefix) const {
	std::cout << prefix << ": " << "impossible" << std::endl;
}

void Converter::Print() const {
	static const print_t printers[] = {
		&Converter::PrintChar,
		&Converter::PrintInt,
		&Converter::PrintFloat,
		&Converter::PrintDouble
	};

	for (int i = 0; i < 4; i++) {
		if (!valid[i]) {
			PrintImpossible(TypeGetStr(static_cast<enum Type> (i)));
		} else {
			(this->*(printers[i]))();
		}
	}
}
