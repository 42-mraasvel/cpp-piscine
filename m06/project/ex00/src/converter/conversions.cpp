#include <climits>
#include <cstdlib>
#include "determine_type.hpp"
#include "converter.hpp"

void Converter::ConvertChar() {
	c = str[0];
	n = static_cast<int> (c);
	f = static_cast<float> (c);
	d = static_cast<double> (c);
}

void Converter::ConvertInt() {
	n = static_cast<int> (strtol(str.c_str(), NULL, 10));
	c = static_cast<char> (n);
	if (n > 255 || n < 0) {
		valid[static_cast<int> (CHAR)] = false;
	}
	f = static_cast<float> (n);
	d = static_cast<double> (n);
}

void Converter::ConvertFloat() {
	std::string arg = str.substr(0, str.length() - 1);
	f = static_cast<float> (strtod(arg.c_str(), NULL));

	c = static_cast<char> (f);
	if (IsInfNanFloat(str) || f > 255.f || f < 0.f) {
		valid[static_cast<int> (CHAR)] = false;
	}

	n = static_cast<int> (f);
	if (IsInfNanFloat(str) || f < INT_MIN || f > static_cast<float> (INT_MAX)) {
		valid[static_cast<int> (INT)] = false;
	}

	d = static_cast<double> (f);
}

void Converter::ConvertDouble() {
	d = strtod(str.c_str(), NULL);

	c = static_cast<char> (d);
	if (IsInfNanDouble(str) || d > 255.0 || d < 0.0) {
		valid[static_cast<int> (CHAR)] = false;
	}

	n = static_cast<int> (d);
	if (IsInfNanDouble(str) || d < INT_MIN || d > INT_MAX) {
		valid[static_cast<int> (INT)] = false;
	}

	f = static_cast<float> (d);
}
